#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2;
ll dp[MN][2];
char s[MN];
int main () {
    int t,n,a,b;
    scan(t);
    while (t--) {
        scan(n,a,b);
        scanf ("%s",s+1);
        dp[0][0] = b; dp[0][1] = LLONG_MAX>>2;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1' || s[i+1] == '1') {
                dp[i][0] = LLONG_MAX>>2;
                dp[i][1] = min(dp[i-1][0] + 2*a + 2*b,dp[i-1][1] + a + 2*b);
            }
            else {
                dp[i][0] = min(dp[i-1][0] + a + b,dp[i-1][1] + 2*a + b);
                dp[i][1] = min(dp[i-1][0] + 2*a + 2*b,dp[i-1][1] + a + 2*b);
            }
        }
        printf ("%lld\n",dp[n][0]);
    }
    return 0;
}