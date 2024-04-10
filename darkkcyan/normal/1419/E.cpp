#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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

const int max_sqrtn = 100000;
vector<int> primes;
bool not_prime[max_sqrtn];
void sieve() {
    for (int i = 2; i < max_sqrtn; ++i) {
        if (not_prime[i]) continue;
        primes.push_back(i);
        for (llong f = 1ll * i * i; f < max_sqrtn; f += i)
            not_prime[f] = true;
    }
}

vector<pair<int, int>> factor(int num) {
    vector<pair<int, int>> ans;
    for (auto i: primes) {
        if (i * i > num) break;
        if (num % i) continue;
        ans.emplace_back(i, 0);
        while (num % i == 0) {
            ++ans.back().second;
            num /= i;
        }
    }
    if (num > 1) ans.emplace_back(num, 1);
    return ans;
}

// Change these
using ans_type = pair<vector<int>, int>;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 1;

mt19937 rng(testing ? 177013 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

int n;
void read() {
    if constexpr(!testing) {
        cin >> n;
    } else {
        ofstream inp("main.inp");
        // generate test
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    for (auto i: ans.first) cout << i << ' ';
    cout << '\n' << ans.second << '\n';
}

ans_type solve() {
    auto ftor = factor(n);
    sort(ftor.begin(), ftor.end(), [](const pair<int, int>&u, const pair<int, int>& v) {
            return u.second > v.second; 
            });
    vector<int> ans;
    if (ftor[0].second == 1 and len(ftor) >= 3) {
        int u = ftor[0].first, v = ftor[1].first, t = ftor[2].first;
        ftor.erase(ftor.begin(), ftor.begin() + 3);
        
        ans = {u, u * v, v, v * t, t, t * u, u * v * t};
    }
    
    for (auto [val, c]: ftor) {
        DB(db(val) << db(c));
        vector<int> other = ans;
        if (!len(other)) other.push_back(1);
        else other.insert(prev(other.end()), 1);
        rep(i, c) {
            for (auto& x: other) x *= val;
            clog << db(other) << endl;
            ans.insert(ans.end(), other.begin(), other.end());
        }
        clog << db(ans) << endl;
    }
    
    int need_op = __gcd(ans[0], ans.back()) == 1;
    rep(i, len(ans) - 1) {
        need_op += __gcd(ans[i], ans[i + 1]) == 1;
    }
    
    return {ans, need_op};
}

ans_type brute() {
    return ans_type();
}

int main(void) {
    sieve();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = testing ? 1000 : 1; 
    if (multitest and !testing) cin >> ntest;
    
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        if constexpr (!testing) {
            print_ans(cout, solve());
            if (print_brute) print_ans(cout << endl << "====" << endl, brute());
        } else {
            auto u = solve();
            auto v = brute();
            assert(u == v);
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker