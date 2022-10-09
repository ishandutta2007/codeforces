#ifdef LOCAL
#define inter
#endif
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

mt19937 rng;
#define rand() ((int)(rng() >> 1))
int n, m;
vector<vector<int>> a;
int asked;
void init() {
#ifdef inter
    cout << "=============" << endl;
    int pn = rand() % 3 + 1;
    int pm = rand() % 3 + 1;
    n = pn * (rand() % 4 + 1);
    m = pm * (rand() % 4 + 1);
    a.assign(n, vector<int>(m));
    rep(i, pn) rep(f, pm) a[i][f] = rand() % 10 + 1;
    rep(i, n) rep(f, m) a[i][f] = a[i % pn][f % pm];
    cout << n << ' ' << m << endl;
    rep(i, n) {
        rep(f, m) cout << setw(4) << a[i][f] << ' ';
        cout << endl;
    }
#else
    cin >> n >> m;
#endif
    asked = 3 * (int)floor(log(n + m) / log(2));
}

bool check_intersect(int h, int w, int r1, int r2, int c1, int c2) {
    return false;
    if (r1 >= r2 and r1 < r2 + h and c1 >= c2 and c1 < c2 + w) return true;
    if (r1 + h - 1 >= r2 and r1 + h - 1 < r2 + h and c1 >= c2 and c1 < c2 + w) return true;
    if (r1 >= r2 and r1 < r2 + h and c1 + w - 1 >= c2 and c1 + w - 1< c2 + w) return true;
    if (r1 + h - 1 >= r2 and r1 + h - 1< r2 + h and c1 + w - 1 >= c2 and c1 + w - 1< c2 + w) return true;
    return false;
}

int ask(int h, int w, int r1, int c1, int r2, int c2) {
    assert(asked);
    cout << "? " << h << ' ' << w << ' ' << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
    --asked;
#ifdef inter
    --r1;
    --c1;
    --r2;
    --c2;
    assert(h <= n);
    assert(w <= m);
    assert(r1 >= 0 and r1 + h <= n);
    assert(r2 >= 0 and r2 + h <= n);
    assert(c1 >= 0 and c1 + w <= m);
    assert(c2 >= 0 and c2 + w <= m);
    assert(!check_intersect(h, w, r1, c2, r2, c2));
    rep(i, h) rep(f, w) {
        if (a[i + r1][f + c1] != a[i + r2][f + c2]) {
            cout << "= 0 " << endl;
            return false;
        }
    }
    cout << "= 1" << endl;
    return true;
#else
    int ans; cin >> ans;
    return ans;
#endif
}

void answer(int ans) {
    cout << "! " << ans << endl;
#ifdef inter
    auto valid = [&](int h, int w) {
        if (n % h) return false;
        if (m % w) return false;
        asked = INT_MAX;
        rep(i, n / h) rep(f, m / w) {
            if (!i and !f) continue;
            if (!ask(h, w, 1, 1, 1 + i * h, 1 + f * w)) return false;
        }
        return true;
    };
    int exp = 0;
    rep1(i, n) rep1(f, m) {
        exp += valid(i, f);
    }
    cout << "; exp = " << exp << endl;
    assert(ans == exp);
#endif
}

map<int, int> factorize(int num) {
    map<int, int> ans;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i) continue;
        int cnt = 0;
        while (num % i == 0) {
            num /= i;
            ++cnt;
        }
        ans[i] = cnt;
    }
    if (num > 1) ans[num] = 1;
    return ans;
}

void solve() {
    init();
    bool swapped = false;
    auto my_ask = [&](int h, int w, int r1, int c1, int r2, int c2) {
        if (swapped) {
            swap(w, h);
            swap(r1, c1);
            swap(r2, c2);
        }
        return ask(h, w, r1, c1, r2, c2);
    };
    
    int ans = 1;
    rep(_, 2) {
        int u = m, v = n;
        if (swapped) swap(u, v);
        int cur_ans = 1;
        auto fac = factorize(u);
        
        auto check = [&](int w) -> bool {
            if (w == u) return true;
            int sz = w;
            for (; sz * 2 <= u; sz <<= 1) {
                if (!my_ask(v, sz, 1, 1, 1, sz + 1)) return false;
            }
            if (sz == u) return true;
            sz /= 2;
            return my_ask(v, sz, 1, u - 2 * sz + 1, 1, u - sz + 1);
        };
        
        for (auto [p, c]: fac) {
            int times = 1;
            int pw = 1;
            rep(i, c) {
                int sz = u / __gcd(p, u);
                if (!check(sz)) break;
                u /= __gcd(p, u);
                pw *= p;
                ++times;
            }
            cur_ans *= times;
            clog << db(p) << db(times) << db(cur_ans) << endl;
        }
        swapped = !swapped;
        ans *= cur_ans;
    }
    answer(ans);
}

int main(void) {
// #ifdef LOCAL 
    // freopen("main.inp", "r", stdin); 
    // freopen("main.out", "w", stdout); 
    // freopen(".log", "w", stderr); 
// #endif 
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#ifdef inter
    while (true) solve();
#else
    solve();
#endif
    
    
    return 0;
}

// vim: foldmethod=marker