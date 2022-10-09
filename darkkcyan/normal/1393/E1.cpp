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
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

function<bool(int, int)> gen_missing_char_cmp(const string& su, const string& sv) {
    using sitor = string::const_iterator;
    
    static auto gen_diff = [](sitor bu, sitor eu, sitor bv, sitor ev) {
        int lu = (int)(eu - bu), lv = (int)(ev - bv);
        int l = min(lu, lv);
        vector<int> ans(l + 1);
        ans.back() = l;
        int prev = l;
        for (int i = l; i--; ) {
            if (bu[i] == bv[i]) ans[i] = prev;
            else prev = ans[i] = i;
        }
        return ans;
    };
    
    // static hack here. only one instance returned by this function is used at one time.
    // doing this avoid copying new data.
    static vector<int> first_diff, miss1_first_diff, miss2_first_diff;
    first_diff = gen_diff(su.begin(), su.end(), sv.begin(), sv.end());
    miss1_first_diff = gen_diff(su.begin() + 1, su.end(), sv.begin(), sv.end());
    miss2_first_diff = gen_diff(su.begin(), su.end(), sv.begin() + 1, sv.end());
    
    auto cmp_char = [=](int u, int v) {
        char cu = u >= len(su) ? ' ' : su[u];
        char cv = v >= len(sv) ? ' ' : sv[v];
        return cu < cv;
    };
    
    return [=](int u, int v) {
        // const int ml = min(len(su), len(sv)); 
        // deb(u, v, first_diff, miss1_first_diff, miss2_first_diff, su, sv); 
        if (int t = first_diff[0]; t < min(u, v)) return cmp_char(t, t);
        if (u < v) {
            if (int t = miss1_first_diff[u]; t < v) return cmp_char(t + 1, t);
        } else {
            if (int t = miss2_first_diff[v]; t < u) return cmp_char(t, t + 1);
        }
        
        int t = first_diff[max(u, v) + 1];
        return cmp_char(t, t);
    };
}

const llong mod = (llong)1e9 + 7;
const int maxn = 101010;
int n;
string s[maxn];
vector<int> mchs[maxn];
vector<llong> dp[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n; 
    rep(i, n) {
        DB(""; deb(i));
        cin >> s[i]; 
        s[i] += ' ';
        rep(f, len(s[i])) mchs[i].push_back(f);
        sort(mchs[i].begin(), mchs[i].end(), gen_missing_char_cmp(s[i], s[i]));
        // for (auto f: mchs[i]) { 
            // string temp = s[i]; temp.erase(temp.begin() + f);  
            // deb(f, temp); 
        // } 
        
        if (i == 0) {
            dp[i].resize(len(s[i]), 1);
            continue;
        }
        
        dp[i].resize(len(s[i]));
        llong sum_prev = 0;
        int u = 0;
        
        auto cmp = gen_missing_char_cmp(s[i], s[i - 1]);
        
        rep(v, len(s[i])) {
            while (u < len(s[i - 1]) and !(cmp(mchs[i][v], mchs[i - 1][u]))) {
                sum_prev += dp[i - 1][u];
                if (sum_prev >= mod) sum_prev -= mod;
                ++u;
            }
            dp[i][v] = sum_prev;
        }
        deb(dp[i]);
    }
    
    llong ans = 0;
    for (auto& i: dp[n - 1]) {
        ans += i;
        if (ans >= mod) ans -= mod;
    }
    cout << ans;
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker