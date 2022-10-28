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
#define N 1000005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
pii h[N];
int n,m,a[N],fa[N],dis[N],rd[N];
bool inq[N];
vector<int> G[N];
inline int bh(int x,int y)
{
    return (x-1)*m+y;
}


inline int findr(int x)
{
    return fa[x]==x?x:fa[x]=findr(fa[x]);
}

int main()
{
    int i,j,mn=INF+1,mi,A,B;
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
        fa[i]=i;
        if(a[i]<mn) mn=a[i],mi=i;
    }
    //debug(mi);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            h[j]=MP(a[bh(i,j)],bh(i,j));
        sort(h+1,h+1+m);
        for(j=1;j<m;j++)
            if(h[j].fi==h[j+1].fi)
            {
                A=h[j].se,B=h[j+1].se;
                if(findr(A)!=findr(B))
                    fa[fa[A]]=fa[B];
            }

    }
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
            h[i]=MP(a[bh(i,j)],bh(i,j));
        sort(h+1,h+1+n);
        for(i=1;i<n;i++)
            if(h[i].fi==h[i+1].fi)
            {
                A=h[i].se,B=h[i+1].se;
                if(findr(A)!=findr(B))
                    fa[fa[A]]=fa[B];
            }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            h[j]=MP(a[bh(i,j)],bh(i,j));
        sort(h+1,h+1+m);
        for(j=1;j<m;j++)
            if(h[j].fi==h[j+1].fi)
               ;
            else
            {
                A=findr(h[j].se),B=findr(h[j+1].se);
                G[A].push_back(B);
                rd[B]++;
            }
    }
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
            h[i]=MP(a[bh(i,j)],bh(i,j));
        sort(h+1,h+1+n);
        for(i=1;i<n;i++)
            if(h[i].fi==h[i+1].fi)
                ;
            else
            {
                A=findr(h[i].se),B=findr(h[i+1].se);
                G[A].push_back(B);
                rd[B]++;
            }
    }
    queue<int> q;
    for(i=1;i<=n*m;i++)
        if(!rd[i]&&fa[i]==i)
            dis[i]=1,q.push(i),inq[i]=1;
    int x,v,w;
    while(!q.empty())
    {
        x=q.front(),q.pop(); inq[x]=0;
        for(i=0;i<G[x].size();i++)
        {
            v=G[x][i];
            rd[v]--;
            dis[v]=max(dis[v],dis[x]+1);
            if(rd[v]==0)
                q.push(v);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("%d ",dis[findr(bh(i,j))]);
        printf("\n");
    }
    //cout<<ans<<endl;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))