#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=120000;
struct Edge{
    int from,to,cost;
}E[N];
const int inf=(int)1e9+2;
int n,m,k,a[N];
int fa[N];
int getfather(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=getfather(fa[x]);
}

void unite(int x,int y)
{
    x=getfather(x); y=getfather(y);
    fa[y]=fa[x];
}

bool same(int x,int y){return getfather(x)==getfather(y);}

bool check(int mid)
{
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(E[i].cost>=mid) continue;
        unite(E[i].from,E[i].to);
    }
    for(int i=2;i<=k;i++) if(!same(a[i],a[1])) return 1;
    return 0;
}

void init()
{
}

void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].cost);
    }
    int l=1,r=inf,mid,best;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1,best=mid;
        else r=mid-1;
    }
    for(int i=1;i<=k;i++) printf("%d ",best);
    puts("");
}

int main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}