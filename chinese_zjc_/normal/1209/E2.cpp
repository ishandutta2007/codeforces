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
#define PI 3.14159265358979323
#define INF 0x1fffffffffffffff
using namespace std;
int t,n,m,dp[2][1<<13],dpp[1<<13][15];
struct c{
    int Max,num[15];
    inline int& operator [](const int &TMP)
    {
        return num[TMP];
    }
    inline bool operator <(const c &TMP)const
    {
        return Max>TMP.Max;
    }
}a[4005];
inline int dfs(int now,int i)
{
	if(dpp[now][i])
	{
		return dpp[now][i];
	}
	int tmp=0;
	for(int l=0;l<n;++l)
	{
		for(int o=0;o<n;++o)
		{
			if(now&(1<<o))
			{
				tmp+=a[i][(l+o)%n];
			}
		}
		dpp[now][i]=max(dpp[now][i],tmp);
		tmp=0;
	}
	return dpp[now][i];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(register int i=1;i<=m;++i)
        {
            a[i].Max=0;
        }
        for(register int i=0;i<n;++i)
        {
            for(register int j=1;j<=m;++j)
            {
                cin>>a[j][i];
                a[j].Max=max(a[j].Max,a[j][i]);
            }
        }
        sort(a+1,a+1+m);
        m=min(m,n);
        memset(dp[0],0,sizeof(dp[0]));
		memset(dpp,0,sizeof(dpp));
        for(register int i=1;i<=m;++i)
        {
            memset(dp[i&1],0,sizeof(dp[i&1]));
            for(register int j=0;j<1<<n;++j)
            {
				if(!(j&1))
				{
					continue;
				}
                for(register int k=j;k>=0;--k)
                {
					k&=j;
                    if((k&j)!=k)
                    {
                        continue;
                    }
                    int add=k^j;
                    // for(int l=0;l<n;++l)
                    // {
                    //     int tmp=0;
                    //     for(int o=0;o<n;++o)
                    //     {
                    //         if(add&(1<<o))
                    //         {
                    //             tmp+=a[i][(o+l)%n];
                    //         }
                    //     }
                    //     dp[i&1][j]=max(dp[i&1][j],dp[!(i&1)][k]+tmp);
                    // }
					dp[i&1][j]=max(dp[i&1][j],dp[!(i&1)][k]+dfs(add,i));
                }
                // cout<<dp[i&1][j]<<' ';
            }
            // cout<<endl;
        }
        cout<<dp[m&1][(1<<n)-1]<<endl;
    }
    return 0;
}