#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline void readi(int &x);
const int maxn=100005;
int n,Q,ans[maxn];
int S,bel[maxn],bn,L[maxn],R[maxn];
int sum[maxn],cnt[maxn];
int tc[maxn],col[maxn];
int adj[maxn*2],next[maxn*2],head[maxn*2],tot=1;
struct ask
{
    int id;
    int l,r,k;
}q[maxn];

int fa[maxn],dfn[maxn],las[maxn],Index;

bool cmpl(const ask &a,const ask &b)
{return (bel[a.l]==bel[b.l])?a.r<b.r:a.l<b.l;}

void addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;next[tot]=head[v];head[v]=tot;}

void tdfs(int x)
{
    dfn[x]=++Index;
    for(int i=head[x];i;i=next[i])
        if(adj[i]!=fa[x])
        {
            fa[adj[i]]=x;
            tdfs(adj[i]);
        }
    las[x]=Index;
}

void init()
{
    readi(n),readi(Q);
    for(int i=1;i<=n;i++)
        readi(tc[i]);
    for(int i=1,u,v;i<n;i++)
    {
        readi(u),readi(v);
        addedge(u,v);
    }
    tdfs(1);
    for(int i=1;i<=n;i++)
        col[dfn[i]]=tc[i];
    for(int i=1,j,k;i<=Q;i++)
    {
        readi(j),readi(k);
        q[i].id=i;
        q[i].l=dfn[j],q[i].r=las[j],q[i].k=k;
    }
    S=sqrt(n)+2;
    for(int i=1;i<=n;i+=S)
    {
        bn++;
        L[bn]=i;
        R[bn]=min(n,i+S-1);
        for(int j=L[bn];j<=R[bn];j++)bel[j]=bn;
    }
    sort(q+1,q+Q+1,cmpl);
}

void work()
{
    int l=1,r=0;
    for(int i=1;i<=Q;i++)
    {
        while(l>q[i].l)sum[++cnt[col[--l]]]++;
        while(r<q[i].r)sum[++cnt[col[++r]]]++;
        while(l<q[i].l)sum[cnt[col[l++]]--]--;
        while(r>q[i].r)sum[cnt[col[r--]]--]--;
        ans[q[i].id]=sum[q[i].k];
    }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
}

int main()
{
    init();
    work();
    return 0;
}

inline void readi(int &x)
{char c;for(c=getchar();c>'9'||c<'0';c=getchar());
x=c^'0';for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+(c^'0');}