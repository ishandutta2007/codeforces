#include<bits/stdc++.h>
#define N 100000
using namespace std;
struct node
{
    int l,r,fa;
    inline void operator+=(node &b)
    {
        b.fa=fa,l=min(l,b.l),r=max(r,b.r);
    }
}t[N+5];
int n,val[N*2+5],cnt,a[N+5],b[N+5],tot;
vector<int> v[N*8+5];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
inline int gf(int x) {return t[x].fa==x?x:t[x].fa=gf(t[x].fa);}
inline void merge(int u,int v) {if((u=gf(u))!=(v=gf(v))) t[u]+=t[v];}
inline void add(int x,int l,int r,int le,int ri,int val)
{
    if(l>ri || r<le) return;
    if(le<=l && r<=ri) return v[x].push_back(val),void();
    add(lson,l,mid,le,ri,val),add(rson,mid+1,r,le,ri,val);
}
inline void modify(int x,int l,int r,int p,int u)
{
    if(!v[x].empty())
    {
        for(int v:v[x]) merge(u,v);
        v[x].resize(1,u);
    }
    if(l!=r) p<=mid?modify(lson,l,mid,p,u):modify(rson,mid+1,r,p,u);
}
inline bool inside(int u,node t) {return t.l<u && u<t.r;}
int main()
{
    scanf("%d",&n);
    for(int i=1,opt,l,r;i<=n;++i)
    {
        scanf("%d %d %d",&opt,&l,&r);
        if(opt==1) val[++cnt]=l,val[++cnt]=r,++tot,t[tot]={l,r,tot};
        else a[i]=l,b[i]=r;
    }
    sort(val+1,val+1+cnt),cnt=unique(val+1,val+1+cnt)-val-1,tot=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i])
        {
            int u=gf(a[i]),v=gf(b[i]);
            puts(u==v || inside(t[u].l,t[v]) || inside(t[u].r,t[v])?"YES":"NO");
        }
        else
        {
            ++tot;
            t[tot].l=lower_bound(val+1,val+1+cnt,t[tot].l)-val;
            t[tot].r=lower_bound(val+1,val+1+cnt,t[tot].r)-val;
            int templ=t[tot].l,tempr=t[tot].r;
            modify(1,1,cnt,templ,tot),modify(1,1,cnt,tempr,tot);
            if(t[tot].l<t[tot].r-1) add(1,1,cnt,t[tot].l+1,t[tot].r-1,tot);
        }
    }
    return 0;
}