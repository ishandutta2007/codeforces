#include<bits/stdc++.h>
#define N 200000
using namespace std;
int n,q;
#define lson x<<1
#define rson lson|1
#define mid ((l+r)>>1)
namespace segment_tree1
{
    bool t[N*4];
    inline void modify(int x,int l,int r,int le,int ri)
    {
        if(le<=l && r<=ri) return t[x]=1,void();
        if(l>ri || r<le) return;
        modify(lson,l,mid,le,ri);
        modify(rson,mid+1,r,le,ri);
        if(!t[x]) t[x]=t[lson]&t[rson];
    }
    inline bool query(int x,int l,int r,int le,int ri)
    {
        if(l>ri || r<le || t[x]) return 1;
        if(le<=l && r<=ri) return 0;
        return query(lson,l,mid,le,ri)&
        query(rson,mid+1,r,le,ri);
    }
}
namespace segment_tree2
{
    int t[N*4];
    inline void modify(int x,int l,int r,int p,int val)
    {
        if(l==r) return t[x]=max(t[x],val),void();
        p<=mid?modify(lson,l,mid,p,val):
        modify(rson,mid+1,r,p,val);
        t[x]=max(t[lson],t[rson]);
    }
    inline int query(int x,int l,int r,int le,int ri)
    {
        if(le<=l && r<=ri) return t[x];
        if(l>ri || r<le) return 0;
        return max(query(lson,l,mid,le,ri),
        query(rson,mid+1,r,le,ri));
    }
}
#undef lson
#undef rson
#undef mid
inline int find_pre(int x)
{
    int l=1,r=x;
    while(l<r)
    {
        int mid=(l+r)>>1;
        segment_tree1::query(1,1,n,mid,x-1)?
            r=mid:l=mid+1;
    }
    return l;
}
inline int find_nxt(int x)
{
    int l=x,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        segment_tree1::query(1,1,n,x+1,mid)?
            l=mid:r=mid-1;
    }
    return l;
}
set<pair<int,int> > s;
inline bool check(int p)
{
    int l=find_pre(p),r=find_nxt(p);
    return segment_tree2::query(1,1,n,p,r)>=l;
}
int main()
{
    scanf("%d %d",&n,&q);
    int opt,l,r,x,p;
    while(q--)
    {
        scanf("%d",&opt);
        if(!opt)
        {
            scanf("%d %d %d",&l,&r,&x);
            if(x) segment_tree2::modify(1,1,n,r,l);
            else segment_tree1::modify(1,1,n,l,r);
        }
        else
        {
            scanf("%d",&p);
            if(segment_tree1::query(1,1,n,p,p)) puts("NO");
            else puts(check(p)?"YES":"N/A");
        }
    }
    return 0;
}