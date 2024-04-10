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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int pri[105],num[105],zy[105];
int G[65540][60],sz[65540];
int dp[105][65540],jl[105][65540],fr[105][65540];
bool vis[105]={0};
void getprime()
{
    int i,j,cou=0;
    for(i=2;i<=60;i++)
        if(!vis[i])
        {
            num[i]=cou;
            pri[++cou]=i;
            for(j=i*i;j<=60;j+=i)
                vis[j]=1;
        }
}
void init()
{
    int i,j;
    zy[1]=0;
    for(i=2;i<=58;i++)
        for(j=2;j<=58;j++)
            if(!vis[j]&&i%j==0)
                zy[i]|=(1<<num[j]);

    for(i=0;i<(1<<16);i++)
    {
        sz[i]=1;
        G[i][1]=1;
        for(j=2;j<=58;j++)
            if(!(i&zy[j]))
            {
                //if(i==(1<<9)&&j==29)
                    //printf("BUGGGGG");
                G[i][++sz[i]]=j;
            }
    }
}
int a[105],b[105];
void inline update(int i,int j,int c,int fj,int k)
{
    if(dp[i][j]==-1||dp[i][j]>c)
    {
        //if(i==5&&j==5)
           // printf("c=%d fj=%d k=%d\n",c,fj,k);
        dp[i][j]=c;
        fr[i][j]=fj;
        jl[i][j]=k;
    }
}
int main()
{
    getprime();
    init();
    int n,i,j,k,c,minw=INF,minj;
    memset(dp,-1,sizeof(dp));
    //printf("num=%d\n",num[29]);
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[0][0]=0;
    //for(j=1;j<=58;j++)
    for(i=0;i<n;i++)
    {
        for(j=0;j<(1<<16);j++)
            if(dp[i][j]!=-1)
            {
                //printf("i=%d j=%d %d %d %d\n",i,j,dp[i][j],fr[i][j],jl[i][j]);
                //update(i+1,j,a[i]-1+dp[i][j],j,1);
                for(k=1;k<=sz[j];k++)
                {
                    c=G[j][k];
                    //if(i+1==5&&(j|zy[c])==5)
                        //printf("cost=%d j=%d c=%d\n",abs(a[i+1]-c)+dp[i][j],j,c);
                    update(i+1,j|zy[c],abs(a[i+1]-c)+dp[i][j],j,c);
                }
            }
    }
    for(j=0;j<(1<<16);j++)
        if(dp[n][j]!=-1)
            if(dp[n][j]<minw)
                minw=dp[n][j],minj=j;
    //cout<<minw<<endl;
    j=minj;
    for(i=n;i;i--)
    {
        //printf("i=%d j=%d %d %d %d\n",i,j,dp[i][j],fr[i][j],jl[i][j]);
        b[i]=jl[i][j];
        j=fr[i][j];
    }
    for(i=1;i<=n;i++)
        printf("%d ",b[i]);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);