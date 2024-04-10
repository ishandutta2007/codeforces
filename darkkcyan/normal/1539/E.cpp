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

struct Range {
    int l, r;
    
    Range() = default;
    Range(const Range& u, const Range& v): l(max(u.l, v.l)), r(min(u.r, v.r)) {}
    
    bool empty() const {
        return l > r;
    }
    
    bool contains(int point) const {
        return l <= point and point <= r;
    }
    
    friend ostream& operator<<(ostream& out, const Range& u) {
        return out << pair{u.l, u.r};
    }
};

int l2(int num) {
    return 31 - __builtin_clz(num);
}

struct SpareTable {
    vector<vector<Range>> data;
    SpareTable(int n, const function<Range(int i)>& get): data(l2(n) + 1, vector<Range>(n)) {
        rep(i, 0, n) data[0][i] = get(i);
        clog << db(data[0]) << endl;
        rep(lv, 1, sz(data)) {
            int i = 0, f = (1 << (lv - 1));
            for (; i + (1 << lv) <= n; ++i, ++f)
                data[lv][i] = Range(data[lv - 1][i], data[lv - 1][f]);
        }
    }
    
    Range get(int l, int r) const {
        int lv = l2(r - l);
        return Range(data[lv][l], data[lv][r - (1 << lv)]);
    }
};

const int maxn = 202020;
int n, m;
int k[maxn];
Range lrange[maxn], rrange[maxn];
int trace[maxn][2];

int find_fit(const SpareTable& st, int point, int pos) {
    int l = pos + 1, r = n + 2;
    while (l < r) {
        int mid = (l + r) / 2;
        if (st.get(pos, mid).contains(point)) l = mid + 1;
        else r = mid;
    }
    clog << db(point) << db(pos) << db(l - 1) << db(st.get(pos, l)) << endl;
    return l - 1;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> k[i];
        cin >> lrange[i].l >> lrange[i].r;
        cin >> rrange[i].l >> rrange[i].r;
    }
    
    SpareTable ls(n + 1, [](int i) { return lrange[i]; });
    SpareTable rs(n + 1, [](int i) { return rrange[i]; });
    
    set<int> cur_trace[2];
    cur_trace[0].insert(0);
    cur_trace[1].insert(0);
    
    vector<vector<pair<int, int>>> events(n + 10);
    events[find_fit(ls, 0, 0)].emplace_back(0, 0);
    events[find_fit(rs, 0, 0)].emplace_back(1, 0);
    
    auto rem_all = [&](vector<pair<int, int>>& evt) {
        for (auto [hand, p]: evt) cur_trace[hand].erase(p);
        evt.clear();
    };
    
    rem_all(events[0]);
    
    memset(trace, -1, sizeof(trace));
    
    rep(i, 1, n + 1) {
        rem_all(events[i]);
        if (!lrange[i].contains(k[i])) {
            cur_trace[1].clear();
        }
        if (!rrange[i].contains(k[i])) {
            cur_trace[0].clear();
        }
        
        if (cur_trace[0].size()) {
            trace[i][1] = *cur_trace[0].begin();
            events[find_fit(rs, k[i], i)].emplace_back(1, i);
        }
        
        if (cur_trace[1].size()) {
            trace[i][0] = *cur_trace[1].begin();
            events[find_fit(ls, k[i], i)].emplace_back(0, i);
        }
        if (trace[i][0] != -1) cur_trace[0].insert(i);
        if (trace[i][1] != -1) cur_trace[1].insert(i);
        rem_all(events[i]);
        
        clog << db(i) << db(trace[i][0]) << db(trace[i][1]) << endl;
    }
    
    if (trace[n][0] == -1 and trace[n][1] == -1) {
        cout << "No";
        return 0;
    }
    
    cout << "Yes\n";
    int hand = 0;
    if (trace[n][hand] == -1) hand = 1;
    
    int p = trace[n][hand];
    vector<int> ans;
    for (int i = n; i > 0; i--) {
        if (i == p) {
            hand = 1 - hand;
            p = trace[i][hand];
        }
        ans.push_back(hand);
    }
    
    for (int i = sz(ans); i--; ) cout << ans[i] << ' ';
    
    return 0;
}

// vim: foldmethod=marker