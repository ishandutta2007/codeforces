#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
const long long inf=2147483647ll*1000000ll;
using namespace std;
int n,w,b,x,q;
long long f[1010][10010],c[1010],cost[1010];
int main()
{
    scanf("%d%d%d%d",&n,&w,&b,&x);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&cost[i]);
    f[0][0]=w;
    for(int i=1;i<=10000;i++)f[0][i]=-inf;
    int ans=0;
    for(int i=1;i<=n;i++)
      for(int j=0;j<=10000;j++)
        {
            f[i][j]=-inf;
            for(int k=0;k<=c[i]&&k<=j;k++)
                if(f[i-1][j-k]>=0)
                    f[i][j]=max(f[i][j],min(f[i-1][j-k]+x,w+1ll*b*(j-k))-cost[i]*k);
            if(f[i][j]>=0)ans=max(ans,j);
        }
    cout<<ans<<endl;
}