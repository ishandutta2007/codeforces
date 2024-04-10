#include<bits/stdc++.h>
#define N 200000
using namespace std;
int n,k,d,a[N+5],b[N+5],st1[N+5],st2[N+5],top1,top2,ansl,ansr=-1;
map<int,int> last;
namespace segment_tree
{
    #define lson x<<1
    #define rson x<<1|1
    #define mid ((l+r)>>1)
    int t[N*4],tag[N*4];
    inline void build(int x,int l,int r)
    {
        t[x]=l;if(l!=r) build(lson,l,mid),build(rson,mid+1,r);
    }
    inline void push_down(int x,int l,int r)
    {
        if(tag[x])
        {
            t[x]+=tag[x];
            if(l!=r) tag[lson]+=tag[x],tag[rson]+=tag[x];
            tag[x]=0;
        }
    }
    inline void add(int x,int l,int r,int le,int ri,int val)
    {
        push_down(x,l,r);
        if(l>ri || r<le) return;
        if(le<=l && r<=ri) return tag[x]+=val,push_down(x,l,r);
        add(lson,l,mid,le,ri,val),add(rson,mid+1,r,le,ri,val),t[x]=min(t[lson],t[rson]);
    }
    inline int query(int x,int l,int r,int le,int ri,int val)
    {
        push_down(x,l,r);
        if(l>ri || r<le || t[x]>val) return n+1;
        if(l==r) return l;
        int lans=query(lson,l,mid,le,ri,val);
        return lans==n+1?query(rson,mid+1,r,le,ri,val):lans;
    }
}
using namespace segment_tree;
int main()
{
    scanf("%d %d %d",&n,&k,&d);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    if(!d)
    {
        int l=1;
        for(int i=1;i<=n;++i)
            if(a[i]!=a[l])
            {
                if(i-l>ansr-ansl+1)
                    ansl=l,ansr=i-1;
                l=i;
            }
        if(n-l>ansr-ansl) ansl=l,ansr=n;
        printf("%d %d",ansl,ansr);
        return 0;
    }
    for(int i=1;i<=n;++i)
        b[i]=(a[i]%d+d)%d,a[i]=(a[i]-b[i])/d;
    build(1,1,n);
    for(int i=1,l=1;i<=n;++i)
    {
        if(b[i]!=b[l]) l=i;
        l=max(l,last[a[i]]+1),last[a[i]]=i;
        for(;top1 && a[i]>a[st1[top1]];--top1)
            add(1,1,n,st1[top1-1]+1,st1[top1],-a[st1[top1]]);
        add(1,1,n,st1[top1]+1,i,a[i]),st1[++top1]=i;
        for(;top2 && a[i]<a[st2[top2]];--top2)
            add(1,1,n,st2[top2-1]+1,st2[top2],a[st2[top2]]);
        add(1,1,n,st2[top2]+1,i,-a[i]),st2[++top2]=i;
        int p=query(1,1,n,l,i,k+i);
        if(i-p>ansr-ansl) ansl=p,ansr=i;
    }
    printf("%d %d",ansl,ansr);
    return 0;
}