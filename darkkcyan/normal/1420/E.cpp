#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

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
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

constexpr bool testing = 0; 
constexpr bool print_brute = 0;
int ntest = testing ? 1000 : 1;

const int maxn = 100;
int n;
int a[maxn];

void read() {
    if constexpr(!testing) {
        cin >> n;
        rep(i, n) cin >> a[i];
    } else {
        n = rand(7) + 1;
        rep(i, n) a[i] = rand(2);
        ofstream inp("main.inp");
        inp << n << '\n';
        rep(i, n) inp << a[i] << ' ';
    }
}

vector<int> brute() {
    vector<int> ans(n * (n - 1) / 2 + 1);
    vector<int> state(a, a + n);
    
    auto cost = [&](const vector<int>& u) {
        vector<int> parts(1, 0);
        for (auto i: u) {
            if (i) parts.emplace_back(0);
            else ++parts.back();
        }
        
        int sum = accumulate(parts.begin(), parts.end(), 0);
        int cur_ans = sum * sum;
        for (auto x: parts) cur_ans -= x * x;
        assert(cur_ans % 2 == 0);
        return cur_ans / 2;
    };
        
    function<void(int, vector<int>)> check = [&](int step, vector<int> s) {
        ans[step] = max(ans[step], cost(s));
        
        if (step == len(ans) - 1) return ;
        rep(i, len(s)) {
            if (!s[i]) continue;
            for (auto f: {i - 1, i + 1}) {
                if (f < 0 or f >= len(s)) continue;
                if (s[f]) continue;
                auto new_s = s;
                new_s[f] = 1;
                new_s[i] = 0;
                check(step + 1, new_s);
            }
        }
    };
    
    check(0, state);
    rep1(i, len(ans) - 1) ans[i] = max(ans[i], ans[i - 1]);
    return ans;
}

vector<int> solve() {
    vector<int> pos1;
    rep(i, n) if (a[i]) pos1.push_back(i);
    int cnt0 = n - len(pos1);
    pos1.push_back(n);
    
    auto dp = vector(n + 1, vector(n + 1, vector(n * n + 1, INT_MAX)));
    
    rep(i, len(pos1)) {
        rep(added, cnt0 + 1) {
            int move_cost = abs(added + i - pos1[i]);
            rep(sum, n * n) {
                int& cur_dp = dp[i][added][sum];
                if (i == 0) {
                    cur_dp = added * added == sum ? move_cost : INT_MAX;
                } else {
                    for (int last = 0; last <= added and last * last <= sum; ++last) {
                        int prev = dp[i - 1][added - last][sum - last * last];
                        if (prev == INT_MAX) continue;
                        cur_dp = min(cur_dp, prev + move_cost);
                    }
                }
                if (cur_dp != INT_MAX) {
                    clog << i << ' ' << added << ' ' << sum << ' ' << cur_dp << endl;
                }
            }
        }
    }
    
    vector<int> ans(n * (n - 1) / 2 + 1, 0);
    
    rep(i, cnt0 * cnt0 + 1) {
        if (i & 1) continue;
        int t = cnt0 * cnt0 - i;
        int pos = dp[len(pos1) - 1][cnt0][t];
        if (pos == INT_MAX) continue;
        ans[pos] = max(ans[pos], i / 2);
    }
    rep1(i, len(ans) - 1) ans[i] = max(ans[i], ans[i - 1]);
    return ans;
}

int main(void) {
    rng.seed(177013);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(ntest--) {
        read();
        if constexpr(!testing) {
            auto ans = solve();
            for (auto i: ans) cout << i << ' ';
            cout << '\n';
            if constexpr (print_brute) {
                auto b = brute();
                for (auto i: b) cout << i << ' ';
                cout << '\n';
            }
        } else {
            auto ans = solve();
            auto expected = brute();
            assert(ans == expected);
            cout << "OK" << endl;
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker