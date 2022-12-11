#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N],m,t[N*4][20],laz[N*4];
void merge(int x){
    int lc=x<<1,rc=x<<1|1;
    for(int i=0;i<20;i++)t[x][i]=t[lc][i]+t[rc][i];
}
void build(int x,int l,int r){
    if(l==r){
        for(int i=0;i<20;i++)t[x][i]+=(a[l]>>i)&1;
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    for(int i=0;i<20;i++)t[x][i]=t[x<<1][i]+t[x<<1|1][i];
}
void change(int x,int l,int r,int ql,int qr,int d){
    if(l>=ql&&r<=qr){
        laz[x]^=d;
        for(int i=0;i<20;i++)if((d>>i)&1)t[x][i]=r-l+1-t[x][i];
        return;
    }
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)change(x<<1,l,mid,ql,qr,d);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,d);
    for(int i=0;i<20;i++)t[x][i]=t[x<<1][i]+t[x<<1|1][i];
}
LL query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr){
        LL ret=0;
        for(int i=0;i<20;i++)ret+=(1ll<<i)*t[x][i];
        return ret;
    }
    int mid=(l+r)>>1;LL ret=0;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)ret+=query(x<<1,l,mid,ql,qr);
    if(qr>mid)ret+=query(x<<1|1,mid+1,r,ql,qr);
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);build(1,1,n);
    for(int i=1,op,l,r,x;i<=m;i++){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)printf("%lld\n",query(1,1,n,l,r));
        else scanf("%d",&x),change(1,1,n,l,r,x);
    }
    return 0;
}