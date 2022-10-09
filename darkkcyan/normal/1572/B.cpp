#include <bits/stdc++.h>
using namespace std;


#define jalsol_orz main   // I did this for a meme :D


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


inline optional<vector<int>> solve(vector<int> a) {
    int n = sz(a);
    vector<int> ans;
    
    auto do_op = [&](int i) {
        assert(i >= 0 and i + 2 < n);
        if (sz(ans) == n) {
            cout << db(ans) << db(a) << db(i) << endl;
            exit(1);
        }
        ans.push_back(i);
        int x = a[i] ^ a[i + 1] ^ a[i + 2];
        a[i] = a[i + 1] = a[i + 2] = x;
    };
    
    if (accumulate(all(a), 0) & 1) return {};
    
    int pref1 = 0;
    while (pref1 < n and a[pref1]) ++pref1;
    
    if (pref1 == n) return {};
    
    pref1 --;
    if (pref1 % 2 == 0) {
        while (pref1 + 2 < n) {
            if (a[pref1 + 1] and a[pref1 + 2]) pref1 += 2;
            else if (!a[pref1 + 1] and !a[pref1 + 2]) {
                do_op(pref1);
                pref1 += 2;
            } else break;
        }
        
        if (pref1 + 2 >= n) return {};
        pref1 ++;
    }
    
    --pref1;
    while (pref1 >= 0) {
        do_op(pref1);
        pref1 -= 2;
    }
    
    assert(a[0] == 0);
    rep(i, 0, n - 2) {
        if (!a[i] and !a[i + 1] and !a[i + 2]) continue;
        int x = a[i] ^ a[i + 1] ^ a[i + 2];
        if (x and !a[i + 1]) continue;
        if (x) {
            do_op(i + 1);
        }
        if (a[i + 1]) do_op(i);
    }
    
    assert(accumulate(all(a), 0) == 0);
    
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (true) {
        int n = rand() % 10 + 1;
        vector<int> a(n);
        rep(i, 0, n) a[i] = rand() & 1;
        
        ofstream inp ("main.inp");
        inp << "1\n";
        inp << n << endl;
        for (auto i: a) inp << i << ' ';
        inp.close();
        
        solve(a);
        cout << "OK" << endl;
    }
}

int jalsol_orz() {
    // check();  
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        auto ans = solve(a);
        if (!ans) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << ans->size() << '\n';
        for (auto i: *ans) cout << i + 1 << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker