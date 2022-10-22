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
int t,n,a[100005],sum[100005],ans,cnt[1000005];
void read(int &x)
{
    x=getchar();
    while('0'>x||x>'9')
    {
        x=getchar();
    }
    x^='0';
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        ans=0;
        ++cnt[n];
        for(int i=1;i<=n;++i)
        {
            read(a[i]);
            sum[i]=sum[i-1]+a[i]-1;
            ans+=cnt[sum[i]+n];
            ++cnt[sum[i]+n];
        }
        cout<<ans<<endl;
    }
    return 0;
}