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
#define N 155
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp1[N][11255],dp2[N][11255],a[N];
void upd1(int &x,int y)
{
    if(x<y) x=y;
}
void upd2(int &x,int y)
{
    if(x>y||x==-1) x=y;
}

int main()
{
    int n,k,s,i,j,l,loc,ans=0,sum=0;
    cin>>n>>k>>s;
    //sw=n*(n-1)/2;
    s=min(s,n*(n-1)/2);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i<=k)
            sum+=a[i];
    }
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    dp1[0][0]=0;
    dp2[0][0]=0;
    for(i=1;i<=k;i++)
    {
        loc=k+1-i;
        for(j=i-1;j>=0;j--)
            for(l=0;l<=s-loc;l++)
            //for(l=s-loc;l>=0;l--)
                if(dp1[j][l]!=-1)
                {
                    //debug(j);
                    //debug(l);
                    upd1(dp1[j+1][l+loc],dp1[j][l]+a[i]);
                }
    }
    for(i=k+1;i<=n;i++)
    {
        loc=i-(k+1);
        for(j=i-1;j>=0;j--)
            for(l=0;l<=s-loc;l++)
            //for(l=s-loc;l>=0;l--)
                if(dp2[j][l]!=-1)
                    upd2(dp2[j+1][l+loc],dp2[j][l]+a[i]);
    }
    for(i=0;i<=min(k,n-k);i++)
        for(j=1;j<=s;j++)
        {
            if(dp1[i][j-1]!=-1)
                upd1(dp1[i][j],dp1[i][j-1]);
            if(dp2[i][j-1]!=-1)
                upd2(dp2[i][j],dp2[i][j-1]);
        }
    for(i=0;i<=min(k,n-k);i++)
        for(j=0;j<=s;j++)
            if(dp1[i][j]!=-1&&dp2[i][s-j]!=-1)
                ans=min(ans,dp2[i][s-j]-dp1[i][j]);
    cout<<sum+ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))
/*
17 7 10
4096 64 512 1 256 16384 8 1024 65536 2 128 32768 4 16 8192 32 2048
*/