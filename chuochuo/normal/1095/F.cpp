#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXE 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE];
ll n,m,V,E,a[MAXN];
ll p[MAXN],r[MAXN];
void init(ll n)
{
    for(ll i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
ll kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    ll res=0;
    for(ll i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    ll res=INF,id=-1;
    V=n; E=0;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        if(a[i]<res) {res=a[i]; id=i;}
    }
    for(ll i=1;i<=n;i++)
    {
        if(i==id) continue;
        es[E++]=(edge){i,id,a[i]+a[id]};
    }
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        es[E++]=(edge){u,v,w};
    }
    printf("%lld\n",kruskal());
    return 0;
}