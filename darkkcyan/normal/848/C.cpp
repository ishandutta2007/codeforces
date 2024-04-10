#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct Query {
    int id, l, r;
};

struct Update {
    int id, pos, prev_pos;
};

const int maxn = 101010;
int n, m;
int a[maxn];

vector<Query> queries[maxn * 2];
vector<Update> updates[maxn * 2];

void add(Query qr) {
    for (int l = qr.l + n, r = qr.r + n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) queries[l++].push_back(qr);
        if (r & 1) queries[--r].push_back(qr);
    }
}
void add(Update upd) {
    for (int p = upd.pos + n; p > 0; p >>= 1) {
        updates[p].push_back(upd);
    }
}

template<int ofs, bool rev>
struct BIT {
    vector<ll> vals;
    BIT() = default;
    BIT(int len): vals(len + ofs + 10, 0) {}
    
    void upd(int i, ll v) {
        i += ofs;
        if (rev) i = sz(vals) - i + 1;
        for (; i < sz(vals); i += i & -i) vals[i] += v;
    }
    
    ll get(int i) const {
        i += ofs;
        if (rev) i = sz(vals) - i + 1;
        ll ans = 0;
        for (; i > 0; i -= i & -i) ans += vals[i];
        return ans;
    }
};

ll ans[maxn];

int old_prev[maxn];
void process(int blk) {
    static BIT<3, true> bit(n + 1);
    auto& qrs = queries[blk];
    auto& upds = updates[blk];
    int it = 0;
    for (auto [id, l, r]: qrs) {
        while (it < sz(upds) and upds[it].id < id) {
            auto [_, pos, prev_pos] = upds[it++];
            bit.upd(old_prev[pos], - (pos - old_prev[pos]));
            bit.upd(prev_pos, pos - prev_pos);
            old_prev[pos] = prev_pos;
        }
        ll cur_ans = bit.get(l);
        ans[id] += cur_ans;
    }
    for (auto [id, pos, prev_pos]: upds) {
        if (old_prev[pos] == -1) continue;
        bit.upd(old_prev[pos], - (pos - old_prev[pos]));
        old_prev[pos] = -1;
        // bit.upd(-1, pos + 1); 
    }
}

void process_all() {
    for (int i = 1; i <= 2 * n; ++i) {
        process(i);
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(old_prev, -1, sizeof(old_prev));
    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    
    vector<set<int>> all_pos(n + 1);
    auto add_upd = [&](int val, int pos, int uid) {
        auto& cur_pos = all_pos[val];
        auto [it, is_new] = cur_pos.insert(pos);
        assert(is_new);
        if (next(it) != cur_pos.end()) {
            add(Update{uid, *next(it), pos});
        }
        if (it != cur_pos.begin()) {
            add(Update{uid, pos, *prev(it)});
        } else {
            add(Update{uid, pos, -1});
        }
    };
    auto rem_upd = [&](int val, int pos, int uid) {
        auto& cur_pos = all_pos[val];
        auto it = cur_pos.find(pos);
        assert(it != cur_pos.end());
        int prev_pos = it == cur_pos.begin() ? -1 : *prev(it);
        if (next(it) != cur_pos.end()) {
            add(Update{uid, *next(it), prev_pos});
        }
        cur_pos.erase(it);
    };
    
    rep(i, 0, n) {
        add_upd(a[i], i, -1);
    }
    
    rep(i, 0, m) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            ans[i] = -1;
            --u;
            rem_upd(a[u], u, i);
            add_upd(a[u] = v, u, i);
        } else {
            add(Query{i, --u, v});
        }
    }
    
    process_all();
    rep(i, 0, m) {
        if (ans[i] == -1) continue;
        cout << ans[i] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker