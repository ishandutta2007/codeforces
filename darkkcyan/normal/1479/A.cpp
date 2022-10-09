#ifdef LOCAL 
#define inter
#endif

#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
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

int n;
#ifdef inter
int __qr;
vector<int> __a;
void init() {
    __qr = 100;
    n = rand() % 10 + 1;
    __a.resize(n);
    rep(i, n) __a[i] = i;
    shuffle(__a.begin(), __a.end(), rng);
    cout << n << endl;
    cout << __a << endl;
}

int ask(int i) {
    --__qr;
    assert(__qr >= 0);
    cout << "? " << i << " === " << __a[i - 1] << endl;
    return __a[i - 1];
}

void answer(int k) {
    cout << "! " << k << endl;
    --k;
    int prev = k ? __a[k - 1] : INT_MAX;
    int nxt = k + 1 < n ? __a[k + 1] : INT_MAX;
    assert(__a[k] < min(prev, nxt));
}
#else
void init() {
    cin >> n;
}
int ask(int i) {
    cout << "? " << i << endl;
    int ans; cin >> ans;
    return ans;
}

void answer(int k) {
    cout << "! " << k << endl;
}
#endif

void solve() {
    auto my_ask = [&](int x) {
        if (1 <= x and x <= n) return ask(x);
        return INT_MAX;
    };
    int l = 1, r = n;
    while (l < r) {
        clog << db(l) << db(r) << endl;
        int mid = (l + r + 1) / 2;
        int amid = my_ask(mid);
        int prv = my_ask(mid - 1);
        if (prv > amid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    vector<int> a;
    for (int i = l - 1; i <= r + 1; ++i) a.push_back(my_ask(i));
    for (int i = l; i <= r; ++i) {
        int u = i - l + 1;
        if (a[u] < min(a[u - 1], a[u + 1])) {
            answer(i);
            return ;
        }
    }
    assert(false);
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef inter
    while (true) {
        cout << "=== test" << endl;
        // freopen("main.out", "w", stdout); 
        init();
        solve();
        cout << "OK" << endl;
    }
#else
    init();
    solve();
#endif
    
    return 0;
}

// vim: foldmethod=marker