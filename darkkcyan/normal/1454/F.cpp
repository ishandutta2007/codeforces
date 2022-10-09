// #define testing   
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////


optional<tuple<int, int, int>> solve(const vector<int>& a) {
    int n = len(a);
    int lgn = 32 - __builtin_clz(n);
    vector min_tab(lgn, vector<int>(n));
    vector max_tab(lgn, vector<int>(n));
    min_tab[0] = max_tab[0] = a;
    rep(i, lgn - 1) {
        for (int pos = 0; pos + (2 << i) <= n; ++pos) {
            min_tab[i + 1][pos] = min(min_tab[i][pos], min_tab[i][pos + (1 << i)]);
            max_tab[i + 1][pos] = max(max_tab[i][pos], max_tab[i][pos + (1 << i)]);
        }
    }
    
    auto get_min = [&](int l, int r) {
        if (l >= r) return INT_MAX;
        int lg = 31 - __builtin_clz(r - l);
        return min(min_tab[lg][l], min_tab[lg][r - (1 << lg)]);
    };
    auto get_max = [&](int l, int r) {
        if (l >= r) return -1;
        int lg = 31 - __builtin_clz(r - l);
        return max(max_tab[lg][l], max_tab[lg][r - (1 << lg)]);
    };
    
    auto first_ok = [](int from, int to, function<bool(int)> fn) {
        int l = from, r = to;
        while (l < r) {
            // clog << l << ' ' << r << endl; 
            int mid = (l + r) / 2;
            if (!fn(mid)) l = mid + 1;
            else r = mid;
        }
        return l;
    };
    
    rep1(i, n - 2) {
        int cur_mx = get_max(0, i);
        int mid_l = first_ok(1, n - i, [&](int length) {
                return get_min(i, i + length) <= cur_mx;
                });
        int mid_r = first_ok(1, n - i, [&](int length) {
                return get_min(i, i + length) < cur_mx;
                });
        
        int right_l = first_ok(1, n - i, [&](int length) {
                return get_max(n - length, n) >= cur_mx;
                });
        int right_r = first_ok(1, n - i, [&](int length) {
                return get_max(n - length, n) > cur_mx;
                });
        if (mid_l >= mid_r or right_l >= right_r) continue;
        if (mid_r - 1+ right_r - 1 + i < n) continue;
        if (mid_l + right_l + i > n) continue;
        clog << db(i) << db(mid_l) << db(mid_r) << db(right_l) << db(right_r) << endl;
        int x = i;
        int y = mid_l;
        while (y < mid_r and ((n - x - y) < right_l or (n - x - y) >= right_r)) ++y;
        int z = n - x - y;
        return {{x, y, z}};
        break;
    }
    return {};
}

bool check_ans(const vector<int>& a, int x, int y, int z) {
    if (x < 1 or y < 1 or z < 1) return false;
    if (x + y + z != len(a)) return false;
    int u = *max_element(a.begin(), a.begin() + x);
    int v = *min_element(a.begin() + x, a.begin() + y + x);
    int t = *max_element(a.begin() + x + y, a.end());
    return (u == v and v == t);
}

bool has_ans(const vector<int>& a) {
    rep1(x, len(a)) {
        rep1(y, len(a) - x) {
            int z = len(a) - x - y;
            if (z < 1) continue;
            if (check_ans(a, x, y, z)) {
                cout << x << ' ' << y << ' ' << z << endl;
                return true;
            }
        }
    }
    return false;
}

void stress() {
    while (true) {
        int n = rand() % 10 + 1;
        vector<int> a(n);
        rep(i, n) a[i] = rand() % 10 + 1;
        ofstream inp("main.inp");
        inp << "1\n" << n << '\n';
        for (auto i: a) inp << i << ' ' ;
        inp.close();
        
        auto ans = solve(a);
        if (!ans) {
            if (has_ans(a)) {
                cout << "FAILED: there is an answer\n" << endl;
                exit(0);
            }
        } else {
            auto [x, y, z] = *ans;
            if (!check_ans(a, x, y, z)) {
                cout << "Failed checking\n" << endl;
                exit(0);
            }
        }
        cout << "OK" << endl;
    }
}

int main(void) {
#ifdef testing
    stress();
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        auto ans = solve(a);
        if (ans) {
            cout << "YES\n";
            auto [x, y, z] = *ans;
            cout << x << ' ' << y << ' ' << z << '\n';
        } else cout << "NO\n";
    }
    
    return 0;
}

// vim: foldmethod=marker