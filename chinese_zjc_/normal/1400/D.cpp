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
int n,t,a[3005],sum[3005][3005],ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            for(int j=1;j<=n;++j)
            {
                sum[i][j]=sum[i-1][j];
            }
            ++sum[i][a[i]];
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                ans+=sum[i-1][a[j]]*(sum[n][a[i]]-sum[j][a[i]]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}