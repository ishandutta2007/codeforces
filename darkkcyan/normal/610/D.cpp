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
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct SegTree {
    vector<int> cnt;
    vector<int> val;
    SegTree(int len): cnt(len), val(2 * len) {}
    void upd(int i, int delta) {
        cnt[i] += delta;
        int u = i + sz(cnt);
        val[u] = cnt[i] > 0;
        for (u >>= 1; u > 0; u >>= 1)
            val[u] = val[u << 1] + val[u << 1 | 1];
    }
    
    int get(int l, int r) {
        int ans = 0;
        for (l += sz(cnt), r += sz(cnt); l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans += val[l++];
            if (r & 1) ans += val[--r];
        }
        return ans;
    }
};

struct Seg {
    int x1, y1, x2, y2;
    bool single_covered = false;
    
    Seg() = default;
    
    Seg(int a, int b, int c, int d)
        : x1(min(a, c)), y1(min(b, d)), x2(max(a, c) + 1), y2(max(b, d) + 1) {
    }
    
    operator tuple<int, int, int, int>() const {
        return {x1, y1, x2, y2};
    }
    
    void swap_coor() {
        swap(x1, y1);
        swap(x2, y2);
    }
    
    bool is_hor() const {
        return y2 - y1 == 1;
    }
    bool is_ver() const {
        return x2 - x1 == 1;
    }
    
    friend print_op(Seg) {
        return out << make_tuple(u.x1, u.y1, u.x2, u.y2);
    }
    
    friend bool operator==(const Seg&u, const Seg& v) {
        return (tuple<int, int, int, int>)(u) == (tuple<int, int, int, int>)(v);
    }
    friend bool operator<(const Seg&u, const Seg& v) {
        return (tuple<int, int, int, int>)(u) < (tuple<int, int, int, int>)(v);
    }
};

const int maxn = 101010;

int n;
Seg a[maxn];

ll solve_hor() {
    DB();
    map<int, vector<pair<int, int>>> ranges;
    map<int, vector<int>> singles;
    rep(i, 0, n) {
        if (a[i].is_hor()) {
            if (a[i].is_ver()) {
                singles[a[i].y1].push_back(i);
            } else {
                ranges[a[i].y1].emplace_back(a[i].x1, a[i].x2);
            }
        }
    }
    
    ll ans = 0;
    for (auto& [y, cur_ranges]: ranges) {
        vector<pair<int, int>> moments;
        for (auto [l, r]: cur_ranges) {
            moments.emplace_back(l, 1);
            moments.emplace_back(r, -1);
        }
        
        sort(all(moments));
        auto& cur_single = singles[y];
        sort(all(cur_single), [&](int u, int v) {
                return a[u].x1 < a[v].x1;
                });
        ll cur_ans = 0;
        ll last_pos = -1;
        int it = 0;
        int cnt = 0;
        clog << db(cur_single) << endl;
        for (auto [x, delta]: moments) {
            DB();
            clog << db(x) << db(delta) << endl;
            clog << db(it) << endl;
            for (;it < sz(cur_single) and a[cur_single[it]].x1 < x; ++it) {
                auto u = cur_single[it];
                clog << db(u) << endl;
                a[u].single_covered |= cnt > 0;
            }
            if (cnt > 0) {
                cur_ans += x - last_pos;
            }
            last_pos = x;
            cnt += delta;
        }
        ans += cur_ans;
    }
    return ans;
}

ll count_intersect() {
    vector<int> y_vals;
    vector<tuple<int, int, int>> change_moments;
    vector<pair<int, int>> query_moments;
    
    rep(i, 0, n) {
        if (a[i].is_hor() and a[i].is_ver()) continue;
        if (a[i].is_hor()) {
            change_moments.emplace_back(a[i].x1, a[i].y1, 1);
            change_moments.emplace_back(a[i].x2, a[i].y1, -1);
        }
        if (a[i].is_ver()) {
            query_moments.emplace_back(a[i].x1, i);
        }
        
        y_vals.emplace_back(a[i].y1);
        y_vals.emplace_back(a[i].y2);
    }
    sort(all(y_vals));
    y_vals.erase(unique(all(y_vals)), y_vals.end());
    SegTree st(sz(y_vals));
    ll ans = 0;
    
    sort(all(change_moments));
    sort(all(query_moments), [&](const pair<int, int>& u, const pair<int, int>& v) {
            if (u.first != v.first) return u.first < v.first ;
            return a[u.second].y1 < a[v.second].y1;
            });
    
    auto yid = [&](int y) {
        return (int)(lower_bound(all(y_vals), y) - y_vals.begin());
    };
    
    pair<int, int> prev_col = {INT_MIN, INT_MIN};
    int it = 0;
    for (auto [x, i]: query_moments) {
        DB();
        clog << db(x) << db(i) << endl;
        {DB();
            for (; it < sz(change_moments) and get<0>(change_moments[it]) <= x; ++it) {
                clog << db(it) << endl;
                int y = yid(get<1>(change_moments[it]));
                clog << db(y) << db(change_moments[it]) << endl;
                st.upd(y, get<2>(change_moments[it]));
            }
        }
        int ny1 = yid(a[i].y1);
        int ny2 = yid(a[i].y2);
        clog << db(prev_col) << endl;
        if (prev_col.first != x) {
            prev_col = {x, ny1};
        clog << db(prev_col) << endl;
        }
        clog << "get ans" << db(ny1) << db(ny2) << endl;
        ans += st.get(max(ny1, prev_col.second), ny2);
        clog << db(ans) << endl;
        prev_col.second = max(prev_col.second, ny2);
    }
    return ans;
}

ll solve() {
    sort(a, a + n); 
    n = (int)(unique(a, a + n) - a); 
    auto inter = count_intersect();
    auto hor = solve_hor();
    rep(i, 0, n) a[i].swap_coor();
    auto ver = solve_hor();
    auto ans = hor + ver - inter;
    clog << db(inter) << db(hor) << db(ver) << endl;
    rep(i, 0, n) if (a[i].is_ver() and a[i].is_hor()) ans += !a[i].single_covered;
    return ans;
}

ll brute() {
    const int lim = 100;
    vector<vector<int>> board(2 * lim, vector<int>(2 * lim));
    rep(i, 0, n) {
        rep(x, a[i].x1, a[i].x2)
            rep(y, a[i].y1, a[i].y2)
            board[x + lim][y + lim] = 1;
    }
    ll ans = 0;
    for (auto& i: board) ans += accumulate(all(i), 0ll);
#ifdef LOCAL_DEBUG
    int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
    rep(i, 0, n) {
        min_x = min(min_x, a[i].x1);
        min_y = min(min_y, a[i].y1);
        max_x = max(max_x, a[i].x2);
        max_y = max(max_y, a[i].y2);
    }
    
    cerr << string(3, ' ');
    rep(x, min_x, max_x) cerr << (x % 10 + 10) % 10;
    cerr << endl;
    rep(y, min_y, max_y) {
        cerr << setw(3) << std::left<< y;
        rep(x, min_x, max_x) {
            cerr << (board[x + lim][y + lim] ? '#' : '.');
        }
        cerr << endl;
    }
#endif
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    ofstream inp("main.inp");
    n = rand() % 5 + 1; 
    inp << n << endl;
    rep(i, 0, n) {
        int x1 = rand() % 5 - 3;
        int x2 = rand() % 5 - 3;
        int y1 = rand() % 5 - 3;
        int y2 = rand() % 5 - 3;
        if (rand() & 1) x1 = x2;
        else y1 = y2;
        a[i] = Seg(x1, y1, x2, y2);
        inp << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    }
    
    auto exp = brute();
    auto ans = solve();
    if (exp == ans) {
        cout << "OK" << endl;
        return ;
    }
    cout << "FAILED" << endl;
    inp << db(exp) << db(ans) << endl;
    exit(0);
}

int main() {
    // while (1) check();            
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = Seg(x1, y1, x2, y2);
        clog << db(i) << db(a[i]) << endl;
    }
    
    
#ifdef LOCAL
    cout << endl << brute() << endl;
#endif
    cout << solve();
    
    return 0;
}

// vim: foldmethod=marker