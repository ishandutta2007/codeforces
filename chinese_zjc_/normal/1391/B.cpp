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
int n,t,m,ans;
char a[105][105];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>a[i][j];
            }
        }
        ans=0;
        for(int i=1;i<m;++i)
        {
            if(a[n][i]=='D')
            {
                ++ans;
            }
        }
        for(int i=1;i<n;++i)
        {
            if(a[i][m]=='R')
            {
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}