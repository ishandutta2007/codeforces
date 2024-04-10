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

const int maxn = 501010;
int n, k;
int a[maxn];

bool brute() {
    vector<int> b(a, a + n);
    b.push_back(-1);
    auto check = [&] {
        vector<int> st = {n};
        for (int i = n; i--; ) {
            while (b[st.back()] >= b[i]) st.pop_back();
            if (st.back() - i > k) return false;
            st.push_back(i);
        }
        return true;
    };
    
    if (check()) return true;
    rep(i, 0, n) {
        rep(f, i + 1, n) {
            if (a[i] <= a[f]) continue;
            swap(b[i], b[f]);
            if (check()) return true;
            swap(b[i], b[f]);
        }
    }
    return false;
}

bool solve() {
#define nope() return false;
    a[n] = -1;
    map<int, int> spare;
    
    vector<int> st = {n};
    for (int i = n; i--; ) {
        while (a[st.back()] >= a[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }
    
    clog << db(st) << endl;
    bool used = false;
    rep(i, 1, sz(st)) {
        rep(f, st[i] + 1, st[i - 1]) {
            spare[a[f]] = f;
        }
        if (st[i - 1] - st[i] <= k) continue;
        DB();
        clog << db(i) << endl;
        clog << db(st) << endl;
        clog << db(st[i]) << db(st[i - 1]) << endl;
        clog << db(spare) << endl;
        if (used) nope();
        used = true;
        bool ok = false;
        auto it = spare.lower_bound(a[st[i]]);
        if (it != spare.begin()) {
            --it;
            if (it->first > a[st[i - 1]]) {
                rep(f, st[i] + 1, st[i - 1]) {
                    if (f - st[i] > k or st[i - 1] - f > k) continue;
                    ok = true;
                    swap(a[f], a[it->second]);
                    st.push_back(f);
                    break;
                }
            }
        }
        clog << db(ok) << endl;
        clog << db(st) << endl;
        if (ok) continue;
        if (i > 1 and st[i - 2] - st[i] <= 2 * k) {
            int u = st[i - 2] - k;
            clog << db(u) << endl;
            swap(a[st[i - 1]], a[u]);
            st[i - 1] = u;
            clog << db(st) << endl;
            continue;
        }
        nope();
    }
    clog << db(vector<int>(a, a + n)) << endl;
    return true;
}

auto print_ans(bool x) {
    cout << (x ? "YES" : "NO") << endl;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() { 
    while (true) {
        ofstream inp("main.inp");
        n = rand() % 10 + 1;
        k = rand() % n + 1;
        rep(i, 0, n) a[i] = rand() % 10 + 1;
        inp << n << ' ' << k << endl;
        rep(i, 0, n) inp << a[i] << ' ';
        inp << endl;
        
        auto exp = brute();
        auto ans = solve();
        inp << db(ans) << db(exp) << endl;
        inp.close();
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        }
        cout << "FAILED" << endl;
        exit(0);
    }
}

int main() {  
    // check();       
#ifdef LOCAL 
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    
    
#ifdef LOCAL
    print_ans(brute());
#endif
    print_ans(solve());
    
    return 0;
}

// vim: foldmethod=marker