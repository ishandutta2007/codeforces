#include<bits/stdc++.h>
#define N 150000
using namespace std;
int n,m,p,tag[N*4],a[N+5];
struct node
{
    pair<int,int> a[5];int cnt;
    inline void init(int val,int len) {cnt=1,a[0]={val,len};}
    inline node operator+(const node &b) const
    {
        node ret=*this;
        auto add=[&](pair<int,int> val)
        {
            for(int i=0;i<ret.cnt;++i)
                if(ret.a[i].first==val.first)
                    {ret.a[i].second+=val.second;return;}
            if(ret.cnt!=p) return ret.a[ret.cnt++]=val,void();
            for(int i=0;i<ret.cnt;++i)
                if(ret.a[i].second<val.second) swap(ret.a[i],val);
            for(int i=0;i<ret.cnt;++i) ret.a[i].second-=val.second;
        };
        for(int i=0;i<b.cnt;++i) add(b.a[i]);
        return ret;
    }
    inline void print()
    {
        printf("%d ",cnt);for(int i=0;i<cnt;++i)
            printf("%d%c",a[i].first," \n"[i==cnt-1]);
    }
}t[N*4];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
inline void build(int x,int l,int r)
{
    if(l==r) return t[x].init(a[l],1);
    build(lson,l,mid),build(rson,mid+1,r);
    t[x]=t[lson]+t[rson];
}
inline void push_down(int x,int l,int r)
{
    if(!tag[x]) return;
    t[x].init(tag[x],r-l+1);
    if(l!=r) tag[lson]=tag[rson]=tag[x],tag[x]=0;
}
inline void modify(int x,int l,int r,int le,int ri,int id)
{
    push_down(x,l,r);if(l>ri || r<le) return;
    if(le<=l && r<=ri) return tag[x]=id,push_down(x,l,r);
    modify(lson,l,mid,le,ri,id);
    modify(rson,mid+1,r,le,ri,id);
    t[x]=t[lson]+t[rson];
}
inline node query(int x,int l,int r,int le,int ri)
{
    push_down(x,l,r);if(le<=l && r<=ri) return t[x];
    if(ri<=mid) return query(lson,l,mid,le,ri);
    if(le>mid) return query(rson,mid+1,r,le,ri);
    return query(lson,l,mid,le,ri)+query(rson,mid+1,r,le,ri);
}
int main()
{
    scanf("%d %d %d",&n,&m,&p),p=100/p;
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    build(1,1,n);
    for(int i=1,opt,l,r,id;i<=m;++i)
    {
        scanf("%d %d %d",&opt,&l,&r);
        if(opt==1) scanf("%d",&id),modify(1,1,n,l,r,id);
        else query(1,1,n,l,r).print();
    }
    return 0;
}