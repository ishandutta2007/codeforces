//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,a[300005],l1,l2,dp[2][300005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    l1=n/k;
    l2=n/k+1;
    fill(dp[0]+1,dp[0]+1+n,INF);
    for(int i=1;i<=k;++i)
    {
        fill(dp[i&1],dp[i&1]+1+n,INF);
        int lim=min(l2*(i-1)+l1,n);
        for(int j=l1*i;j<=lim;++j)
        {
            dp[i&1][j]=min(dp[i&1][j],dp[!(i&1)][j-l1]+a[j]-a[j-l1+1]);
        }
        lim=min(l2*i,n);
        for(int j=l1*(i-1)+l2;j<=lim;++j)
        {
            dp[i&1][j]=min(dp[i&1][j],dp[!(i&1)][j-l2]+a[j]-a[j-l2+1]);
        }
    }
    cout<<dp[k&1][n]<<endl;
    return 0;
}