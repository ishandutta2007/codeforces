// #define multitest 
#ifdef LOCAL
// #define testing   
#define print_brute 
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

using ans_type = llong;

int n, k;
vector<llong> a;
void read() {
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

struct Data {
    int id;
    int cnt;
    Data(int i, int c = 1) : id(i), cnt(c) {}
    
    llong mx() const {
        return (a[id] + cnt - 1) / cnt;
    }
    
    int count_mx() const {
        int ans = (int)(a[id] % cnt);
        if (ans == 0) ans = cnt;
        return ans;
    }
    
    llong sum() const {
        int c = count_mx();
        llong cur_mx = mx();
        return c * cur_mx * cur_mx + (cnt - c) * (cur_mx - 1) * (cur_mx - 1);
    }
    
    friend bool operator<(const Data&u , const Data& v) {
        llong sv = u.sum() + Data(v.id, v.cnt + 1).sum();
        llong su = v.sum() + Data(u.id, u.cnt + 1).sum();
        if (su == sv) return u.id < v.id;
        return su < sv;
    }
};
 
    
ans_type solve() {
    set<Data> prio;
    rep(i, n) prio.emplace(i);
    
    rep(i, k - n) {
        auto big = *prio.begin();
        prio.erase(prio.begin());
        big.cnt ++;
        prio.insert(big);
    }
    llong ans = 0;
    for (auto& i: prio) {
        llong mx = i.mx();
        int c = i.count_mx();
        ans += 1ll * c * (mx * mx);
        if (c < i.cnt) {
            ans += (i.cnt  - c) * ((mx - 1) * (mx - 1));
        }
    }
    return ans;
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
ans_type brute();
#ifndef testing
int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = 1;
#ifdef multitest
    cin >> ntest;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        auto ans = solve();
        print_ans(cout, ans);
#ifdef print_brute
        auto br = brute();
        print_ans(cout << endl << "====" << endl, br);
        cout << endl << "==============" << endl;
#endif
    }
    return 0;
}
#else
void gen_test(int cur_test) {
    ofstream inp("main.inp");
    n = rand() % 100 + 1;
    k = rand() % 100 + n;
    a.resize(n, (k + n - 1) / n);
    rep(i, n) {
        int u = rand() % n;
        int v = rand() % n;
        llong max_mv = a[v] - 1;
        if (max_mv == 0) continue;
        llong mv = rand() % max_mv;
        a[u] += mv;
        a[v] -= mv;
    }
    inp << n << ' ' << k << endl;
    rep(i, n) inp << a[i] << ' ';
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        auto ans = solve();
        auto br = brute();
        assert(ans == br);
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    vector<llong> dp(k + 1, (llong)1e18);
    sort(a.rbegin(), a.rend());
    dp[0] = 0;
    rep(i, n) {
        vector<llong> new_dp(k + 1, (llong)1e18);
        rep(prv, k + 1) {
            rep1(split, k) {
                if (prv + split > k) break;
                llong cur_mx = (a[i] + split - 1) / split;
                int cnt = (int)(a[i] % split);
                if (cnt == 0) cnt = split;
                new_dp[prv + split] = min(new_dp[prv + split], 
                    cnt * cur_mx * cur_mx +
                    (split - cnt) * (cur_mx - 1) * (cur_mx - 1) + dp[prv]
                );
            }
        }
        clog << db(i) << db(new_dp) << endl;
        dp = move(new_dp);
    }
    return dp[k];
}

// vim: foldmethod=marker