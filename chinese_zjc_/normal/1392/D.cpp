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
int n,t,dp[200005],ans;
string s;
const string g[]={"RL","RRL","RLL","RRLL"};
int diff(string A,string B)
{
    int tmp=0;
    for(int i=0;i<(int)A.length();++i)
    {
        if(A[i]!=B[i])
        {
            ++tmp;
        }
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        s=' '+s;
        ans=INF;
        for(int l=1;l<=5;++l)
        {
            dp[0]=0;
            dp[1]=INF;
            for(int i=2;i<=n;++i)
            {
                dp[i]=dp[i-2]+diff("RL",s.substr(i-1,2));
                if(i>=3)
                {
                    dp[i]=min(dp[i],dp[i-3]+diff("RRL",s.substr(i-2,3)));
                    dp[i]=min(dp[i],dp[i-3]+diff("RLL",s.substr(i-2,3)));
                    if(i>=4)
                    {
                        dp[i]=min(dp[i],dp[i-4]+diff("RRLL",s.substr(i-3,4)));
                    }
                }
            }
            ans=min(ans,dp[n]);
            s=' '+s.substr(2,n-1)+s[1];
        }
        cout<<ans<<endl;
    }
    return 0;
}