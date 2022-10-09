#ifdef LOCAL
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

const int maxn = 201010;
int n, m;
llong a[maxn];
int qr[maxn];

struct Event {
    llong time;
    int u, v;
    
    friend bool operator<(const Event& u, const Event& v) {
        if (u.time == v.time) {
            if (u.u == u.v) return u.v < v.v;
            return u.u < v.u;
        }
        return u.time < v.time;
    }
};

vector<int> solve() {
    map<llong, int> precal_ans;
    const int max_k = (int)1e9 + 100;
    precal_ans[max_k] = 1;
    
    vector<llong> pref_sum(n + 1);
    rep(i, n) pref_sum[i + 1] = pref_sum[i] + a[i];
    
    auto cal_event = [&](int start, int stop) {
        int cnt = stop - start;
        return Event{(pref_sum[stop] - pref_sum[start] + cnt - 1) / cnt, start, stop};
    };
    
    set<Event> prio;
    set<int> pos;
    rep(i, n - 1) {
        prio.emplace(cal_event(i, i + 1));
        pos.insert(i);
    }
    pos.insert(n - 1);
    pos.insert(n);
    
    int cur_ans = 1;
    while (len(prio)) {
        auto [time, u, v] = *--prio.end();
        prio.erase(--prio.end());
        DB("JOIN");
        clog << db(u) << db(v) << endl;
        clog << db(time) << endl;
        
        auto it = pos.find(v);
        int nxt = *next(it);
        prio.erase(cal_event(*it, nxt));
        pos.erase(it);
        precal_ans[time] = cur_ans = max(cur_ans, nxt - u);
        
        if (nxt >= n) continue;
        prio.emplace(cal_event(u, nxt));
    }
    clog << db(precal_ans) << endl;
    
    vector<int> ans(m);
    transform(qr, qr + m, ans.begin(), [&](int k) -> int {
            auto it = (precal_ans.upper_bound(k));
            return it->second - 1;
    });
    return ans;
}

vector<int> brute() {
    vector<int> ans(m);
    transform(qr, qr + m, ans.begin(), [](int k) -> int {
        int cur_ans = 0;
        llong sum = 0;
        int cnt = 0;
        rep(i, n) {
            sum += a[i];
            ++cnt;
            if (sum > k * cnt) continue;
            cur_ans = max(cur_ans, cnt - 1);
            sum = 0;
            cnt = 0;
        }
        cur_ans = max(cur_ans, cnt - 1);
        return cur_ans;
    });
    return ans;
}
    
int main(void) {
#ifdef testing
    rep(testcase, 10000000) {
        n = rand() % 10 + 1;
        m = rand() % 20 + 1;
        rep(i, n) a[i] = rand() % 10 + 1;
        rep(i, m) qr[i] = rand() % 10 + 1;
        sort(qr, qr + m);
        ofstream inp("main.inp");
        inp << n << ' ' << m << '\n';
        rep(i, n) inp << a[i] << ' ';
        inp << '\n';
        rep(i, m) inp << qr[i] << ' ';
        inp << '\n';
        auto ans = solve();
        auto exp = brute();
        inp << ans << endl << exp << endl;
        inp.close();
        if (ans == exp) {
            cout << "OK" << ' ' << testcase << endl;
            continue;
        }
        cout << "FAILED" << endl;
        return 0;
    }
    
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> qr[i];
    auto ans = solve(); 
    // auto ans = brute(); 
    for (auto i: ans) {
        cout << i << ' ';
    }
    
    
    return 0;
}

// vim: foldmethod=marker