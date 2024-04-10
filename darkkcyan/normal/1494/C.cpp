#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        
        auto solve_side = [&](auto bu, auto eu, auto bv, auto ev) {
            DB();
            // clog << db(vector(bu, eu)) << endl; 
            // clog << db(vector(bv, ev)) << endl; 
            vector<bool> having(ev - bv);
            int cnt_having = 0;
            for (auto iu = bu, iv = bv; iv < ev; ++iv) {
                while (iu < eu and *iu < *iv) ++ iu;
                if (iu < eu and *iu == *iv) {
                    having[iv - bv] = true;
                    ++cnt_having;
                }
            }
            int ans = cnt_having;
            int cnt = 0;
            for (auto iv = bv; iv < ev; ++iv) {
                while (bu < eu and *bu < *iv) {
                    ++ bu;
                    ++cnt;
                }
                cnt_having -= having[iv - bv];
                if (!cnt) continue;
                auto p = lower_bound(bv, ev, *iv - cnt + 1);
                ans = max(ans, (int)(iv - p) + 1 + cnt_having);
            }
            return ans;
        };
        
        int first_pos_a = 0;
        while (first_pos_a < n and a[first_pos_a] < 0) {
            a[first_pos_a] *= -1;
            ++ first_pos_a;
        }
        int first_pos_b = 0;
        while (first_pos_b < m and b[first_pos_b] < 0) {
            b[first_pos_b] *= -1;
            ++ first_pos_b;
        }
        clog << db(first_pos_a) << db(first_pos_b) << endl;
        clog << db(a) << endl;
        clog << db(b) << endl;
        int ans = solve_side(a.begin() + first_pos_a, a.end(), b.begin() + first_pos_b, b.end());
        ans += solve_side(a.rbegin() + n - first_pos_a, a.rend(), b.rbegin() + m - first_pos_b, b.rend());
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker