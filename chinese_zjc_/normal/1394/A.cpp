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
int d,n,m,a[100005],sum[100005],g,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>d>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    a[n+1]=INF;
    while(a[++g]<=m);
    --g;
    for(int i=n;i>g;--i)
    {
        int l=(n-i)*(d+1)+1,r=(n-i+1)*(d+1);
        if(n-g>r||l>n)
        {
            continue;
        }
        ans=max(ans,sum[g]-sum[g-min(g,n-l)]+sum[n]-sum[i-1]);
    }
    if(g==n)
    {
        ans=sum[n];
    }
    cout<<ans<<endl;
    return 0;
}