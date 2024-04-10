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

int ask(int num) {
    cout << num << endl;
    int r; cin >> r;
    assert(r != -1);
    return r;
}

int inc_one_mask(int x) {
    int ans = 0;
    for (int i = 1; ; i <<= 1) {
        ans ^= i;
        x ^= i;
        if ((x & i) == i) break;
    }
    return ans;
}

vector<int> to_base(int x, int base) {
    if (x == 0) { return {0}; };
    vector<int> ans;
    while (x) {
        ans.push_back(x % base);
        x /= base;
    }
    return ans;
}

int to_dec(const vector<int>& num, int base) {
    int ans = 0;
    for (int i = sz(num); i--; )  {
        ans = ans * base + num[i];
    }
    return ans;
}

int inc_one_mask(int x, int base) {
    auto xb = to_base(x, base);
    xb.push_back(0);
    vector<int> ans(sz(xb));
    rep(i, 0, sz(xb)) {
        ++ans[i];
        ++xb[i];
        if (xb[i] == base) {
            xb[i] = 0;
            continue;
        }
        break;
    }
    return to_dec(ans, base);
}

int n, k;
void solve_ez() {
    int ans = 0;
    if (ask(0)) return;
    while (true) {
        int r= ask(inc_one_mask(ans));
        if (r == 1) break;
        ++ans;
    }
}

void solve_hard() {
    rep(i, 0, n - 1) {
        int r = ask(inc_one_mask(i, k));
        if (r == 1) break;
    }
    
    auto nb = to_base(n - 1, k);
    for (auto& i: nb) {
        i = k - i;
        if (i == k) i = 0;
    }
    int r = ask(to_dec(nb, k));
    assert(r);
}

int main() {
    // rep(i, 0, 100) {  
        // auto xb = to_base(i, 3); 
        // auto inc = inc_one_mask(i, 3); 
        // auto incb = to_base(inc, 3); 
        //  
        // cout << db(i) << db(xb) << db(inc) << db(incb) << endl; 
    // }  
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    freopen(".log", "w", stderr);
#endif
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >> k;
        // if (k == 2) { 
            // solve_ez(); 
        // } else { 
            solve_hard();
        // } 
    }
    
    return 0;
}

// vim: foldmethod=marker