#ifdef LOCAL  
// #define check  
#endif
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

#ifndef check
int ask(int num) {
    cout << num << endl;
    int r; cin >> r;
    assert(r != -1);
    return r;
}
#endif

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

vector<int> add(vector<int> u, vector<int> v, int base) {
    int s = max(sz(u), sz(v));
    u.resize(s);
    v.resize(s);
    rep(i, 0, s) {
        u[i] += v[i];
        if (u[i] >= base) u[i] -= base;
    }
    return u;
}

vector<int> sub(vector<int> u, vector<int> v, int base) {
    int s = max(sz(u), sz(v));
    u.resize(s);
    v.resize(s);
    rep(i, 0, s) {
        u[i] -= v[i];
        if (u[i] < 0) u[i] += base;
    }
    return u;
}

int n, k;
#ifdef check
int ask_time;
int __ans;
int ask(int num) {
    cout << "? " << num << endl;
    --ask_time;
    assert(ask_time >= 0);
    if (num == __ans) {
        return 1;
    }
    
    auto ab = to_base(__ans, k);
    cout << db(__ans) << db(ab) << endl;
    auto nb = to_base(num, k);
    ab = sub(nb, ab, k);
    __ans = to_dec(ab, k);
    cout << db(__ans) << db(ab) << endl;
    return 0;
}
#endif

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
    if (ask(0)) {
        return ;
    }
    
    int sign = -1;
    
    int cur_num = 0;
    rep(i, 1, n) {
        sign *= -1;
        int new_num;
        auto cnb = to_base(cur_num, k);
        auto ib = to_base(i, k);
        vector<int> nnb;
        if (sign == -1) {
            nnb = add(ib, cnb, k);
        } else {
            nnb = sub(cnb, ib, k);
        }
        new_num = to_dec(nnb, k);
        int r = ask(new_num);
        if (r) return ;
        cnb = sub(nnb, cnb, k);
        cur_num = to_dec(cnb, k);
    }
    assert(false);
}

#ifdef check
mt19937 rng;
#define rand() ((int) (rng() >> 1))
void do_check() {
    cout << "TEST" << endl;
    n = rand() % 10 + 1;
    __ans = rand() % n;
    k = rand() % 99 + 2;
    ask_time = n;
    cout << db(n) << db(k) << db(__ans) << endl;
    solve_hard();
}
#endif

int main() {
#ifdef check
    while (true) do_check();
#endif
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