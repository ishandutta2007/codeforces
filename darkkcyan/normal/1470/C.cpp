#ifdef LOCAL
#define inter 
#define testing
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

int n, k;
#ifdef inter
int imposter;
vector<int> a;
int cnt_ask = 1000;
int ask(int pos) {
    --cnt_ask;
    clog << db(cnt_ask) << endl;
    if (cnt_ask < 0) {
        cout << "FAILED exceed" << endl;
        exit(0);
    }
    int ans = a[pos];
    vector<int> b(n);
    rep(i, n) {
        if (i == imposter) continue;
        int prv = (i + n - 1) % n;
        int nxt = (i + 1) % n;
        b[prv] += a[i] / 2;
        b[nxt] += (a[i] + 1) / 2;
    }
    b[(imposter + 1) % n] += a[imposter];
    a = b;
    clog << "? " << pos + 1 << ' ' << ans << endl;
    clog << db(a) << endl;  
    return ans; 
}

void answer(int ans) {
    cout << "! " << ans + 1 << ' ' << imposter + 1 << endl;
    assert(imposter == ans);
}
#else

int ask(int pos) {
    cout << "? " << pos + 1 << endl;
    int ans; cin >> ans;
    return ans;
}

void answer(int num) {
    cout << "! " << num + 1 << endl;
    exit(0);
}
#endif

void solve() {
    if (n <= 100) {
        for (int i = 0; ; i = (i + 1) % n) {
            if (ask(i) == k and ask((i + 1) % n) > k) {
                answer(i);
                return ;
            }
        }
    }
    int s = (int)sqrt(n) + 1;
    rep(i, s) ask(0);
    clog << db("done init") << endl;
    int min_pos = -1, max_pos = -1;
    auto upd = [&](int pos) {
        rep(f, 2) {
            int x = (pos + f) % n;
            int t = ask(x);
            if (t < k) min_pos = x;
            if (t > k) max_pos = x;
        }
    };
    for (int i = 0; i < n; i += s) {
        upd(i);
    }
    clog << db("done probing") << endl;
    upd(n - 2);
    clog << db(min_pos) << db(max_pos) << endl;
    assert(min_pos != -1);
    assert(max_pos != -1);
    int length = (max_pos - min_pos + n) % n;
    int l = 0, r = length;
    while (l <= r) {
        int mid = (r + l) / 2;
        int x = min_pos + mid;
        if (x >= n) x -= n;
        int t = ask(x );
        if (t == k) {
            answer(x);
            return ;
        }
        if (t < k) l = mid + 1;
        else r = mid - 1;
    }
    assert(false);
}

int main(void) {
// #ifdef LOCAL 
    // freopen("main.inp", "r", stdin); 
    // freopen("main.out", "w", stdout); 
    // freopen(".log", "w", stderr); 
// #endif 
#ifdef inter
    while (true)  {
        cnt_ask = 1000;
        // n = rand() % 100000 + 4;  
        // k = (rand() % (int)4e8) * 2 + 2;  
        n = 100000; 
        k = 2;
        imposter = rand() % n;
        cout << db(n) << db(k)<< db(imposter + 1) << endl;
        a.assign(n, k);
        solve();
        cout << "OK" << endl;
        cout << string(10, '#') << endl;
    }
#endif
    cin >> n >> k;
    solve();
    
    return 0;
}

// vim: foldmethod=marker