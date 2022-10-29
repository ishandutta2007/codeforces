#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
ll dp[MAXN],fact[MAXN];
int main()
{
    fact[0]=1;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    dp[1]=1;
    for(ll i=2;i<=n;i++) dp[i]=1LL*(dp[i-1]+fact[i-1]+MOD-1)*i%MOD;
    printf("%lld\n",dp[n]);
    return 0;
}