#ifdef LOCAL
#define testing    
#endif
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


map<vector<int>, int> brute_ans;
int brute(vector<int> arr) {
    auto it = brute_ans.find(arr);
    if (it != brute_ans.end()) return it->second;
    if (len(arr) == 1) return INT_MAX;
    rep(i, len(arr) - 1) if (arr[i] > arr[i + 1]) return brute_ans[arr] = 0;
    int ans = INT_MAX;
    rep(i, len(arr) - 1) {
        auto b = arr;
        b[i] ^= b[i + 1];
        b.erase(b.begin() + i + 1);
        auto x = brute(b);
        if (x != INT_MAX) ans = min(ans, x + 1);
        clog << db(arr) << db(b) << db(x) << db(ans) << endl;
    }
    clog << db(arr) << db(ans) << endl;
    return brute_ans[arr] = ans;
}

int n;
vector<int> a;
int brute() {
    int ans = brute(a);
    if (ans == INT_MAX) return -1;
    return ans;
}

void gen() {
    ofstream inp("main.inp");
    n = rand() % 5;
    a.resize(n);
    rep(i, n) a[i] = rand() % 10;
    sort(a.begin(), a.end());
    inp << n << endl;
    rep(i, n) inp << a[i] << ' ';
}

int solve() {
    rep(i, n - 2) {
        if ((a[i + 1] ^ a[i + 2]) < a[i]) {
            return 1;
        }
    }
    
    int ans = INT_MAX;
    rep(i, n - 1) {
        int xor_left = 0;
        for (int f = i; f >= 0; --f) {
            xor_left ^= a[f];
            int xor_right = 0;
            for (int g = i + 1; g < n; ++g) {
                xor_right ^= a[g];
                if (xor_left > xor_right) ans = min(ans, i - f + g - i - 1);
            }
        }
    }
    
    if (ans == INT_MAX) ans = -1;
    return ans;
}

int main(void) {
#ifdef testing
    while (true) {
        gen();
        auto ans = solve();
        auto exp = brute();
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        }
        cout << "FAILED " << endl;
        cout << ans << ' ' << exp << endl;
        return 0;
    }
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for (auto& i: a) cin >> i;
    cout << solve() << endl;
    // cout << brute() << endl; 
    return 0;
    
    return 0;
}

// vim: foldmethod=marker