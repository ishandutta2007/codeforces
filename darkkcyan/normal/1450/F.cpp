#ifdef LOCAL
#define testing  
#endif // LOCAL
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

const int maxn = 101010;
int n;
int a[maxn];

void gen() {
    ofstream inp("main.inp");
    n = rand() % 10 + 1;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % n + 1;
    }
    inp << 1 << endl<< n << endl;
    rep(i, n) inp << a[i] << ' ';
}

int brute() {
    int ans = INT_MAX;
    vector<int> pos(n);
    rep(i, n) pos[i] = i;
    do {
        bool ok  = true;
        rep1(i, n - 1) {
            if (a[pos[i]] == a[pos[i - 1]]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        int cur_ans = 0;
        rep(i, n - 1) {
            cur_ans += abs(pos[i] - pos[i + 1]) > 1;
        }
        ans = min(ans, cur_ans);
    } while (next_permutation(pos.begin(), pos.end()));
    return ans == INT_MAX ? -1 : ans;
}

vector<int> cnt_breakable(n + 1), cnt_unbreakable(n + 1);
int get_total_same(int x) {
    return cnt_breakable[x] + cnt_unbreakable[x];
}
struct cmp {
    bool operator()(int u, int v) const {
        int x = get_total_same(u);
        int y = get_total_same(v);
        if (x != y) return x > y;
        if (cnt_breakable[u] != cnt_breakable[v]) return cnt_breakable[u] > cnt_breakable[v];
        return u < v;
    }
};

int solve() {
    int count_same = 0;
    vector<int> freq(n + 1);
    rep(i, n) freq[a[i]]++;
    rep(i, n - 1) count_same += a[i] == a[i + 1];
    int max_freq = *max_element(freq.begin(), freq.end());
    if (max_freq > (n + 1) / 2) return -1;
    freq.assign(n + 1, 0);
    freq[a[0]]++;
    freq[a[n - 1]]++;
    rep(i, n - 1) if (a[i] == a[i + 1]) {
        freq[a[i]]++;
        freq[a[i + 1]]++;
    }
    return count_same + max(0, *max_element(freq.begin(), freq.end()) - count_same - 2);
}

void stress() {
    while (true) {
        gen();
        auto u = solve();
        auto v = brute();
        if (u == v) {
            cout << "nice" << endl;
            continue;
        }
        cout << "Failed " << u << ' ' << v << endl;
        exit(0);
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
        DB("test");
        cin >> n;
        rep(i, n) cin >> a[i];
        auto ans = solve(); 
        // auto ans = brute(); 
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker