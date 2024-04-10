// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

/*{{{*/
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int debug = 1;
#define DB(...) stringstream CONCAT(ss, __LINE__); CONCAT(ss, __LINE__) << __VA_ARGS__; debug_block CONCAT(dbbl, __LINE__)(CONCAT(ss, __LINE__).str())
#else
int debug = 0;
#define DB(...)
#endif
int __db_level = 0;
#define clog if (debug) cerr << string(__db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const int max_alpha = 26;
const int maxn = 444;
string s, t;
int nxt[maxn][max_alpha];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        DB(deb(testcase));
        cin >> s >> t;
        rep(i, max_alpha) nxt[len(s)][i] = len(s);
        for (int i = len(s); i--; ) {
            memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
            nxt[i][s[i] - 'a'] = i;
        }

        bool ok = false;
        for (int left_length = len(t); left_length >= 1; left_length --) {
            int right_length = len(t) - left_length;
            DB(deb(left_length _ right_length));
            string t_left = t.substr(0, left_length);
            string t_right = t.substr(left_length);
            debln(t_left);
            debln(t_right);

            vector<vector<int>> dp(left_length + 1, vector<int>(right_length + 1, len(s) + 1));
            dp[0][0] = 0;
            rep(left, left_length + 1)
            rep(right, right_length + 1) {
                if (!left and !right) continue;
                if (left and dp[left - 1][right] <= len(s)) {
                    int new_ans = nxt[dp[left - 1][right]][t_left[left - 1] - 'a'] + 1;
                    dp[left][right] = min(dp[left][right], new_ans);
                }
                if (right and dp[left][right - 1] <= len(s)) {
                    int new_ans = nxt[dp[left][right - 1]][t_right[right - 1] - 'a'] + 1;
                    dp[left][right] = min(dp[left][right], new_ans);
                }
            }

            debln(dp);
            if (dp[left_length][right_length] < len(s) + 1) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}