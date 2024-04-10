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
int t,n,m,dp[2][1<<12];
struct c{
    int Max;
    vector<int> num;
    int& operator [](const int &TMP)
    {
        return num[TMP];
    }
    bool operator <(const c &TMP)const
    {
        return Max>TMP.Max;
    }
}a[2005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            a[i].Max=0;
            a[i].num.assign(15,0);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>a[j][i%n];
                a[j].Max=max(a[j].Max,a[j][i%n]);
            }
        }
        sort(a+1,a+1+m);
        m=min(m,n);
        memset(dp[0],0,sizeof(dp[0]));
        for(int i=1;i<=m;++i)
        {
            memset(dp[i&1],0,sizeof(dp[i&1]));
            for(int j=0;j<1<<n;++j)
            {
                for(int k=0;k<=j;++k)
                {
                    if((k&j)!=k)
                    {
                        continue;
                    }
                    int add=k^j;
                    for(int l=0;l<n;++l)
                    {
                        int tmp=0;
                        for(int o=0;o<n;++o)
                        {
                            if(add&(1<<o))
                            {
                                tmp+=a[i][(o+l)%n];
                            }
                        }
                        dp[i&1][j]=max(dp[i&1][j],dp[!(i&1)][k]+tmp);
                    }
                }
                // cout<<dp[i&1][j]<<' ';
            }
            // cout<<endl;
        }
        cout<<dp[m&1][(1<<n)-1]<<endl;
    }
    return 0;
}