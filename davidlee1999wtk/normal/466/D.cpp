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
#define INF 1000000000
#define N 2005
#define fi first
#define se second
#define P 1000000007
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,h;
int a[N],dp[N][N],b[N];
void upd(int &x,int y)
{
    x+=y;
    if(x>=P) x-=P;
}

int main()
{
    int i,j;
    LL ans=1;
    cin>>n>>h;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]),b[i]=a[i];
        if(a[i]>h) ans=0;
    }
    n++;
    b[0]=h;
    a[0]=a[n]=h;
    for(i=n;i;i--)
    {
        a[i]=a[i]-a[i-1];
        //debug(a[i]);
        if(a[i]<-1||a[i]>1)
            ans=0;
    }
    if(ans==0)
    {
        printf("0\n");
        return 0;
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
        for(j=0;j<=n;j++)
            if(dp[i-1][j]>0&&j+b[i-1]==h)
            {
                //debug(i-1);
                //debug(j);
                //debug(dp[i-1][j]);
                if(a[i]==1&&j)
                    upd(dp[i][j-1],(LL)j*dp[i-1][j]%P);
                else if(a[i]==0)
                {
                    upd(dp[i][j],(LL)(j+1)*dp[i-1][j]%P);

                        //upd(dp[i][j],dp[i-1][j]);
                    //upd(dp[i][j+1],dp[i-1][j]);
                    //if(j) upd(dp[i][j-1],dp[i-1][j]);
                }
                else
                    upd(dp[i][j+1],dp[i-1][j]);
            }

    cout<<dp[n][0]<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);