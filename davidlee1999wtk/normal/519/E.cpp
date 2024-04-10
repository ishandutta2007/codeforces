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
#define fi first
#define se second
#define N 100005
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int fa[N][20],dep[N],maxd,lg;
int n,sz[N];
vector<int> G[N];
void initlca()
{
    int i,j;
    lg=int(log(maxd)/log(2)+0.5);
    for(j=1;j<=lg;j++)
        for(i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}

inline int lca(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    int i;
    //debug(lg);
    for(i=lg;i>=0;i--)
        if(dep[fa[v][i]]>=dep[u])
            v=fa[v][i];
    if(u==v) return u;
    for(i=lg;i>=0;i--)
        if(fa[v][i]!=fa[u][i])
            u=fa[u][i],v=fa[v][i];
    return fa[v][0];
}

void dfs(int x)
{
    int i,len=G[x].size(),v;
    maxd=max(maxd,dep[x]);
    for(i=0;i<len;i++)
    {
        v=G[x][i];
        if(v!=fa[x][0])
        {
            dep[v]=dep[x]+1;
            fa[v][0]=x;
            dfs(v);
            sz[x]+=sz[v];
        }
    }
    sz[x]++;
}

int get(int x,int b)
{
    for(int i=lg;i>=0;i--)
        if(b&(1<<i))
            x=fa[x][i];
    return x;
}

int main()
{
    int a,b,m,c,d1,d2,d,y,i;
    cin>>n;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fa[1][0]=1,dep[1]=1;
    dfs(1);
    initlca();
    //debug(fa[6][0]);
    //debug(fa[2][0]);
    //debug(dep[2]);
    //debug(dep[6]);
    //debug(lca(2,15));
    //return 0;
    cin>>m;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        c=lca(a,b);
        //debug(a);
        //debug(c);
        d=dep[a]-dep[c]+dep[b]-dep[c];
        if(d&1)
            printf("0\n");
        else if(a==b)
            printf("%d\n",n);
        else
        {
            d1=dep[a]-dep[c];
            d2=dep[b]-dep[c];
            d=d/2;
            if(d1==d)
            {
                c=get(a,d-1);
                y=get(b,d-1);
                printf("%d\n",n-sz[c]-sz[y]);
            }
            else
            {
                //debug(d1),debug(d2),debug(d);
                if(d1>d2)
                    c=get(a,d),y=get(a,d-1);
                else c=get(b,d),y=get(b,d-1);
                //debug(c);
                //debug(y);
                printf("%d\n",sz[c]-sz[y]);
            }
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
15
1 2
1 3
1 4
2 5
2 6
2 7
5 8
6 9
9 14
14 15
7 10
4 13
3 11
3 12
6
10 15
13 12
2 15
8 4
15 12
6 13

*/