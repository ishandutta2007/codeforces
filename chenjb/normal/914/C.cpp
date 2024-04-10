#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#define inf 1000000007
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
long long dp[1110][1110][2],ans;
int a[1110],n,k;
int judge(int x)
{
    int cnt=0;
    while (x!=1)
    {
        cnt++;
        int tx=0;
        for(;x;x>>=1)tx+=x&1;
        x=tx;
    }
    return cnt;
}
char s[10010];
int main()
{
    scanf("%s",s);
    n=strlen(s);
    for(int i=1;i<=n;i++)a[i]=s[i-1]-'0';
    cin>>k;
    memset(dp,0,sizeof(dp));
    if(k==0){ puts("1"); return 0; }
    else
    {
        dp[0][0][1]=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i])
            {
                for(int j=0;j<=1000;j++)dp[i][j][0]=1ll*((dp[i][j][0]+dp[i-1][j][0])%inf+dp[i-1][j][1])%inf;
                for(int j=1;j<=1000;j++)
                {
                    dp[i][j][0]=1ll*(dp[i][j][0]+dp[i-1][j-1][0])%inf;
                    dp[i][j][1]=1ll*(dp[i][j][1]+dp[i-1][j-1][1])%inf;
                } 
            }
            else if(a[i]==0)
            {

                for(int j=0;j<=1000;j++)
                {
                    dp[i][j][0]=1ll*(dp[i][j][0]+dp[i-1][j][0])%inf;
                    dp[i][j][1]=1ll*(dp[i][j][1]+dp[i-1][j][1])%inf;
                }
                for(int j=1;j<=1000;j++)dp[i][j][0]=1ll*(dp[i][j][0]+dp[i-1][j-1][0])%inf;
            }
        }
        
        for(int i=1;i<=1000;i++)
        {
            if(judge(i)==k-1)ans=((ans+dp[n][i][0])%inf+dp[n][i][1])%inf;
        }
    }
    if (k==1)ans=((ans+inf-1)%inf + inf )%inf;
    cout<<ans%inf<<endl;
    return 0;
}