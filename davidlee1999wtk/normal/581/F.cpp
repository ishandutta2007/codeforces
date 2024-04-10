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
#define N 5005
#define K 2501
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
short int dp[N][2][N],g[N][2][2][N];
int lb,up,sz[N],rt,id[N],n;
vector<int> G[N];
inline void upd(short int &x,short int y)
{
    if(x>y) x=y;
}

void dfs(int x,int fa)
{
    //debug(x);
    int i,len=G[x].size(),v,lj,rj,lk,rk,c1,c2,j,k,op,now,nxt;
    short int *f1,*f2,*f3;
    if(id[x]==1)
    {
        sz[x]=1;
        dp[x][0][1+K]=0,dp[x][1][-1+K]=0;
        dp[x][1][1+K]=n;
        dp[x][0][-1+K]=n;
        dp[x][0][K]=n;
        dp[x][1][K]=n;
        return;
    }
    sz[x]=0;
    nxt=0,now=1;
    g[x][nxt][0][K]=0;
    g[x][nxt][1][K]=0;
    for(i=0;i<len;i++)
    {
        v=G[x][i];
        if(v!=fa)
        {
            dfs(v,x);
            lj=max(-K,-sz[x]);
            rj=min(K,sz[x]);
            lk=max(-K,-sz[v]);
            rk=min(K,sz[v]);
            swap(now,nxt);
            for(c1=0;c1<=1;c1++)
            {
                f1=g[x][nxt][c1];
                for(j=lj+lk;j<=rj+rk;j++)
                    if(j>-K&&j<K)
                        f1[j+K]=n;
            }
            for(c1=0;c1<=1;c1++)
                for(c2=0;c2<=1;c2++)
                {
                    op=c1^c2;
                    f1=g[x][now][c1];
                    f2=dp[v][c2];
                    f3=g[x][nxt][c1];
                    for(j=lj;j<=rj;j++)
                        for(k=lk;k<=rk;k++)
                            if(j+k>-K&&j+k<K)
                            {
                                if(v==-1)
                                {
                                    debug(x);
                                    debug(v);
                                    debug(j);
                                    debug(k);
                                    debug(f3[j+k+K]);
                                    debug(f1[j+K]+f2[k+K]+op);
                                    debug(op);
                                }
                                upd(f3[j+k+K],f1[j+K]+f2[k+K]+op);
                            }
                }
            sz[x]+=sz[v];
        }
    }
    lj=max(-K,-sz[x]);
    rj=min(K,sz[x]);
    //debug(lj);
    //debug(rj);
    for(c1=0;c1<=1;c1++)
    {
        f1=g[x][nxt][c1];
        f2=dp[x][c1];
        for(j=lj;j<=rj;j++)
            f2[j+K]=f1[j+K];
    }
}

int main()
{
    int i,a,b;
    cin>>n;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        id[a]++,id[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n==2)
    {
        printf("1\n");
        return 0;
    }
    for(i=1;i<=n;i++)
        if(id[i]!=1)
        {
            rt=i;
            break;
        }
    dfs(rt,0);
    cout<<dp[rt][0][0+K]<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))
/*
3
1 2
1 3

8
1 2
1 3
1 4
4 5
4 6
1 7
1 8
*/