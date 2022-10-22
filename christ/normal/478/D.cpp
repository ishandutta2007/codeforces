#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 2e5+2, MOD = 1e9+7;
int dp[MN];
void uadd (int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
int main () {
    int r,g,s;
    scanf ("%d %d",&r,&g); s = r+g;
    int n = 1;
    while (n*(n+1)/2 <= s) n++; n--;
    int ext = s-n*(n+1)/2;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) 
        for (int j = r; j >= i; j--) 
            uadd(dp[j],dp[j-i]);
    int ans = 0;
    for (int i = max(0,r-ext); i <= r; i++) uadd(ans,dp[i]);
    printf ("%d\n",ans);
    return 0;
}