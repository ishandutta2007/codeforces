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
int T,n,ans,a[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        ans=-INF;
        ans=max(ans,a[1]*a[2]*a[3]*a[4]*a[n]);
        ans=max(ans,a[1]*a[2]*a[n-2]*a[n-1]*a[n]);
        ans=max(ans,a[n-4]*a[n-3]*a[n-2]*a[n-1]*a[n]);
        cout<<ans<<endl;
    }
    return 0;
}