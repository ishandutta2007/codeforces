//
#include <bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
const double pi = 3.141592653589793238462643383279;
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) {return x < y ? x : y;}
template <typename T>
inline T mx(const T x, const T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, const T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, const T y) {(x < y) && (x = y);}
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) {return mx(x, mx(args...));}
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) {return mn(x, mn(args...));}
}
using namespace MyMinMax;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

inline void work(){
    string a, b; cin >> a >> b;
    int ans = a.size() + b.size();
    for (int i = 0;i < (int)a.size();++ i) {
        for (int j = 1;i + j - 1 < (int)a.size();++ j) {
            for (int k = 0;k + j - 1 < (int)b.size();++ k) {
                if(a.substr(i, j) == b.substr(k, j)) chmin(ans, (int)(a.size() + b.size()) - (j << 1));
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T; while(T --) work();
}