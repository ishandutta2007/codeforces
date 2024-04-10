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
int n,m,a[205],b[205];
bool dp[2][1<<9];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
    }
    dp[0][0]=true;
    for(int i=1;i<=n;++i)
    {
        fill(dp[i&1],dp[i&1]+(1<<9),false);
        for(int j=0;j<1<<9;++j)
        {
            for(int k=1;k<=m;++k)
            {
                int tmp=a[i]&b[k];
                dp[i&1][j|tmp]|=dp[!(i&1)][j];
            }
        }
    }
    for(int i=0;i<1<<9;++i)
    {
        if(dp[n&1][i])
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}