#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 3e5+2, MOD = 1e9+7;
ll dp[MN][2]; //best answer ending at i with just a or with both
int main () {
    int n,x;
    scanf ("%d %d",&n,&x);
    vector<ll> a(n+1), b(n+1);
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%lld",&a[i]), b[i] = a[i] * x; 
        sum += a[i];
        sum = max(sum,0LL);
        ans = max(ans,sum);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0]+a[i],0LL);
        dp[i][1] = max(0LL,max(dp[i-1][0]+b[i],dp[i-1][1]+b[i]));
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }
    sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += a[i];
        sum = max(sum,0LL);
        ans = max(ans,sum+max(dp[i-1][0],dp[i-1][1]));
    }
    printf ("%lld\n",ans);
    return 0;
}