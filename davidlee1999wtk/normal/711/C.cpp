#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 105
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL dp[N][N][N];
int c[N],p[N][N];

inline void upd(LL &x,LL y)
{
    //debug(x),debug(y);
    if((x==-1||x>y)&&y!=-1)
        x=y;
}

int main()
{
    int n,m,k,i,j,j1,j2,l,lw,hi;
    LL ans=-1,sum=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&p[i][j]);
    for(i=1;i<=n;i++)
        sum+=p[i][c[i]];
    memset(dp,-1,sizeof(dp));
    if(c[1])
        lw=c[1],hi=c[1];
    else lw=1,hi=m;
    for(j=lw;j<=hi;j++)
        dp[1][1][j]=p[1][j];
    for(i=2;i<=n;i++)
        if(c[i]==0)
        {
            debug(i);
            for(l=1;l<i;l++)
            {
                if(c[i-1]==0)
                {
                    for(j1=1;j1<=m;j1++)
                        if(dp[i-1][l][j1]!=-1)
                        {
                            //debug(dp[i-1][l][j1]);
                        for(j2=1;j2<=m;j2++)
                            if(j1==j2)
                            {
                                //debug(123);
                                upd(dp[i][l][j2],dp[i-1][l][j1]+p[i][j2]);
                            }
                            else
                            {
                                //debug(456);
                                upd(dp[i][l+1][j2],dp[i-1][l][j1]+p[i][j2]);
                            }
                        }
                }
                else
                {
                    for(j1=c[i-1];j1<=c[i-1];j1++)
                        if(dp[i-1][l][j1]!=-1)
                        for(j2=1;j2<=m;j2++)
                            if(j1==j2)
                                upd(dp[i][l][j2],dp[i-1][l][j1]+p[i][j2]);
                            else
                                upd(dp[i][l+1][j2],dp[i-1][l][j1]+p[i][j2]);
                }
            }
        }
        else
        {
            for(l=0;l<i;l++)
            {
                if(c[i-1]==0)
                {
                    for(j1=1;j1<=m;j1++)
                        if(dp[i-1][l][j1]!=-1)
                        for(j2=c[i];j2<=c[i];j2++)
                            if(j1==j2)
                                upd(dp[i][l][j2],dp[i-1][l][j1]+p[i][j2]);
                            else
                                upd(dp[i][l+1][j2],dp[i-1][l][j1]+p[i][j2]);
                }
                else
                {
                    for(j1=c[i-1];j1<=c[i-1];j1++)
                        if(dp[i-1][l][j1]!=-1)
                        for(j2=c[i];j2<=c[i];j2++)
                            if(j1==j2)
                                upd(dp[i][l][j2],dp[i-1][l][j1]+p[i][j2]);
                            else
                                upd(dp[i][l+1][j2],dp[i-1][l][j1]+p[i][j2]);
                }
            }
        }
    i=n,l=k;
    for(j=1;j<=m;j++)
        upd(ans,dp[i][l][j]);
    if(ans==-1)
        cout<<ans<<endl;
    else
        cout<<ans-sum<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/