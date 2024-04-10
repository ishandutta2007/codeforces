#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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

struct Line {
    ll a, b;
    ll id;
    Line(): a(0), b(LLONG_MAX), id(LLONG_MAX) {}
    Line(ll i, ll a_, ll b_): a(a_), b(b_), id(i) {}
    ll operator()(ll x) const {
        return a * x + b;
    }
};

int cmp_line_at(const Line& u, const Line& v, ll x) {
    ll uv = u(x), vv = v(x);
    if (uv < vv) return -1;
    if (uv > vv) return 1;
    if (u.id < v.id) return -1;
    if (u.id > v.id) return 1;
    return 0;
}

struct Lichao {
    vector<ll> val;
    vector<Line> ln;
    Lichao(const vector<ll>& v): val(v), ln(4 * sz(val)) {}
    size_t size() const { return val.size(); }
    pair<ll, ll> get(ll pos, int i, int l, int r) {
        if (pos < val[l] or pos > val[r - 1]) return {LLONG_MAX, LLONG_MAX};
        int mid = (l + r + 1) / 2;
        pair<ll, ll> cur_ans = r - l == 1 ? pair{LLONG_MAX, LLONG_MAX} : pos >= val[mid]
            ? get(pos, 2 * i + 1, mid, r)
            : get(pos, 2 * i, l, mid);
        return min(cur_ans, {ln[i](pos), ln[i].id});
    }
    void add(Line newl, int i, int l, int r) {
        int mid = (l + r + 1) / 2;
        ll vm = val[mid - 1];
        if (cmp_line_at(newl, ln[i], vm) < 0) {
            swap(newl, ln[i]);
        }
        if (r - l == 1) return ;
        int nl_lower = cmp_line_at(newl, ln[i], val[l]) < 0;
        int nr_lower = cmp_line_at(newl, ln[i], val[r - 1]) < 0;
        if (!nl_lower and !nr_lower) return;
        if (nl_lower) add(newl, 2 * i, l, mid);
        else if (nr_lower) add(newl, 2 * i + 1, mid, r);
    }
    
    auto get(ll pos) {
        return get(pos, 1, 0, (int)size());
    }
    void add(Line newL) {
        add(newL, 1, 0, (int)size());
    }
};

struct Query {
    int type;
    int x, y;
};

const int maxm = 301010;
int n, m;
Query queries[maxm];
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<ll> s_val(1, 0);
    rep(i, 0, m) {
        cin >> queries[i].type;
        cin >> queries[i].x;
        if (queries[i].type != 3) {
            continue;
        }
        cin >> queries[i].y;
        s_val.push_back(s_val.back() + queries[i].y);
    }
    
    Lichao lc(s_val);
    ll cur_s = 0;
    ll cur_b = 0;
    ll cnt_cars = n;
    ll offset = 0;
    lc.add(Line(0, 0, 0));
    rep(i, 0, m) {
        if (queries[i].type == 1) {
            cnt_cars += queries[i].x;
            offset -= queries[i].x;
            ll new_id = offset;
            lc.add(Line(new_id, new_id, -cur_b - cur_s * new_id));
        } else if (queries[i].type == 2) {
            ll new_id = cnt_cars + offset;
            cnt_cars += queries[i].x;
            lc.add(Line(new_id, new_id, -cur_b - cur_s * new_id));
        } else {
            cur_b += queries[i].x + queries[i].y * -offset;
            cur_s += queries[i].y;
        }
        auto [min_val, id] = lc.get(cur_s);
        id -= offset;
        cout << id + 1<< ' ' << min_val + cur_b << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker