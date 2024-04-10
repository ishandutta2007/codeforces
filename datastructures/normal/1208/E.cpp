#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define inf 1000000000000000000
using namespace std;
int q,w,n,a[1000005],mx;
struct SGT1{
    int tree[8000005],tag[8000005];
    inline void mem(){
        memset(tree,0,sizeof(tree));
        memset(tag,0,sizeof(tag));
    }
    inline void pushdown(int now,int nowl,int nowr){
        int mid=(nowl+nowr)/2;
        tree[now*2]+=(mid-nowl+1)*tag[now];
        tree[now*2+1]+=(nowr-mid)*tag[now];
        tag[now*2]+=tag[now];
        tag[now*2+1]+=tag[now];
        tag[now]=0;
        return;
    }
    inline void pushup(int now){
        tree[now]=tree[now*2]+tree[now*2+1];
        return;
    }
    inline void update(int now,int nowl,int nowr,int lt,int rt,int k){
        pushdown(now,nowl,nowr);
        if (nowl>=lt&&nowr<=rt){
            tree[now]+=(nowr-nowl+1)*k;
            tag[now]+=k;
            return;
        }
        int mid=(nowl+nowr)/2;
        if (mid>=lt)update(now*2,nowl,mid,lt,rt,k);
        if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,k);
        pushup(now);
        return;
    }
    inline int query(int now,int nowl,int nowr,int pos){
        pushdown(now,nowl,nowr);
        if (nowl==nowr)return tree[now];
        int mid=(nowl+nowr)/2;
        if (pos<=mid)return query(now*2,nowl,mid,pos);
        return query(now*2+1,mid+1,nowr,pos);
    }
}sgt1;
struct SGT2{
    int tree[8000005],tag[8000005];
    inline void mem(){
        for (register int i=0;i<=n*8;i++)tree[i]=tag[i]=-inf;
        return;
    }
    inline void pushup(int now){
        tree[now]=max(tree[now*2],tree[now*2+1]);
        return;
    }
    inline void update(int now,int nowl,int nowr,int pos,int k){
        if (nowl==nowr){
            tree[now]=max(tree[now],k);
            return;
        }
        int mid=(nowl+nowr)/2;
        if (pos<=mid)update(now*2,nowl,mid,pos,k);
        else update(now*2+1,mid+1,nowr,pos,k);
        pushup(now);
        return;
    }
    inline int query(int now,int nowl,int nowr,int lt,int rt){
        if (nowl>=lt&&nowr<=rt)return tree[now];
        int mid=(nowl+nowr)/2,s=-inf;
        if (mid>=lt)s=max(s,query(now*2,nowl,mid,lt,rt));
        if (mid+1<=rt)s=max(s,query(now*2+1,mid+1,nowr,lt,rt));
        return s;
    }
}sgt2;
signed main(){
    cin>>q>>w;
    sgt1.mem();
    while(q--){
        scanf("%lld",&n);
        sgt2.mem();
        mx=0;
        for (int i=1;i<=n;i++)scanf("%lld",&a[i]),mx=max(mx,a[i]);
        for (int i=1;i<=n;i++)sgt2.update(1,1,n,i,a[i]);
        for (int i=1;i<=n;i++){
            int l=max(1ll,n-(w-i)),r=min(n,i);
            int val=sgt2.query(1,1,n,l,r);
            if (w-n+1>i||i>n)val=max(val,0ll);
            sgt1.update(1,1,w,i,i,val);
        }
        for (int i=w;i>w-n&&i>n;i--){
            int l=max(1ll,n-(w-i)),r=min(n,i);
            int val=sgt2.query(1,1,n,l,r);
            if (w-n+1>i||i>n)val=max(val,0ll);
            sgt1.update(1,1,w,i,i,val);
        }
        if (n+1<=w-n)sgt1.update(1,1,w,n+1,w-n,mx);
    }
    for (int i=1;i<=w;i++)printf("%lld ",sgt1.query(1,1,w,i));
    cout<<endl;
    return 0;
}