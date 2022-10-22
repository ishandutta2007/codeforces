#include<bits/stdc++.h>
#define N 100000
using namespace std;
int n,q,a[N+5];
long long pow42[10];
inline void init() {pow42[0]=1;for(int i=1;i<=9;++i) pow42[i]=pow42[i-1]*42;}
inline int find(long long x) {return lower_bound(pow42,pow42+10,x)-pow42;}
namespace segment_tree
{
    #define lson x<<1
    #define rson x<<1|1
    #define mid ((l+r)>>1)
    long long min_val[N*4],tag_modify[N*4],tag_sub[N*4];
    int tag_nxt[N*4];
    inline void push_down(int x,int l,int r)
    {
        if(tag_sub[x])
        {
            if(~tag_modify[x])
            {
                tag_modify[x]-=tag_sub[x];
                for(;tag_modify[x]<0;++tag_nxt[x])
                    tag_modify[x]+=pow42[tag_nxt[x]+1]-pow42[tag_nxt[x]];
            }
            else min_val[x]-=tag_sub[x];
            if(l!=r) tag_sub[lson]+=tag_sub[x],tag_sub[rson]+=tag_sub[x];
            tag_sub[x]=0;
        }
        if(~tag_modify[x])
        {
            min_val[x]=tag_modify[x];
            if(l!=r)
            {
                tag_modify[lson]=tag_modify[rson]=tag_modify[x];
                tag_nxt[lson]=tag_nxt[rson]=tag_nxt[x];
                tag_sub[lson]=tag_sub[rson]=0;
            }
        }
    }
    inline void build(int x,int l,int r)
    {
        if(l==r) return min_val[x]=tag_modify[x]=pow42[tag_nxt[x]=find(a[l])]-a[l],void();
        build(lson,l,mid),build(rson,mid+1,r),tag_modify[x]=-1;
        min_val[x]=min(min_val[lson],min_val[rson]);
    }
    inline long long query(int x,int l,int r,int p)
    {
        push_down(x,l,r);if(l==r) return pow42[tag_nxt[x]]-tag_modify[x];
        return p<=mid?query(lson,l,mid,p):query(rson,mid+1,r,p);
    }
    inline void modify(int x,int l,int r,int le,int ri,long long val,int nxt)
    {
        push_down(x,l,r);if(l>ri || r<le) return;
        if(le<=l && r<=ri) return min_val[x]=tag_modify[x]=val,tag_nxt[x]=nxt,void();
        modify(lson,l,mid,le,ri,val,nxt),modify(rson,mid+1,r,le,ri,val,nxt);
        tag_modify[x]=-1,min_val[x]=min(min_val[lson],min_val[rson]);
    }
    inline void add(int x,int l,int r,int le,int ri,int val)
    {
        push_down(x,l,r);if(l>ri || r<le) return;
        if(le<=l && r<=ri && (min_val[x]>=val || ~tag_modify[x]))
            return tag_sub[x]=val,push_down(x,l,r);
        add(lson,l,mid,le,ri,val),add(rson,mid+1,r,le,ri,val);
        tag_modify[x]=-1,min_val[x]=min(min_val[lson],min_val[rson]);
    }
    #undef lson
    #undef rson
    #undef mid
}
using namespace segment_tree;
int main()
{
    scanf("%d %d",&n,&q),init();
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    build(1,1,n);
    int opt,l,r,x;
    while(q--)
    {
        scanf("%d",&opt);
        if(opt==1) scanf("%d",&x),printf("%lld\n",query(1,1,n,x));
        else if(opt==2) scanf("%d %d %d",&l,&r,&x),modify(1,1,n,l,r,pow42[find(x)]-x,find(x));
        else if(opt==3) {scanf("%d %d %d",&l,&r,&x);while(add(1,1,n,l,r,x),!min_val[1]);};
    }
    return 0;
}