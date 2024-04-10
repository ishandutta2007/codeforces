#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,m,mx[N*4];LL sum[N*4];
void build(int x,int l,int r){
    if(l==r){scanf("%d",&mx[x]);sum[x]=mx[x];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
    sum[x]=sum[x<<1]+sum[x<<1|1];
}
void change(int x,int l,int r,int ql,int qr,int d){
    if(mx[x]<d||l>qr||r<ql)return;
    if(l==r){mx[x]%=d,sum[x]=mx[x];return;}
    int mid=(l+r)>>1;
    change(x<<1,l,mid,ql,qr,d);
    change(x<<1|1,mid+1,r,ql,qr,d);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
    sum[x]=sum[x<<1]+sum[x<<1|1];
}
void change(int x,int l,int r,int p,int d){
    if(l==r){mx[x]=sum[x]=d;return;}
    int mid=(l+r)>>1;
    p<=mid?change(x<<1,l,mid,p,d):change(x<<1|1,mid+1,r,p,d);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
    sum[x]=sum[x<<1]+sum[x<<1|1];
}
LL query(int x,int l,int r,int ql,int qr){
    if(l>qr||r<ql)return 0;
    if(l>=ql&&r<=qr)return sum[x];
    int mid=(l+r)>>1;
    return query(x<<1,l,mid,ql,qr)+query(x<<1|1,mid+1,r,ql,qr);
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1,op,l,r,x;i<=m;i++){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)printf("%lld\n",query(1,1,n,l,r));
        else if(op==2)scanf("%d",&x),change(1,1,n,l,r,x);
        else change(1,1,n,l,r);
    }
    return 0;
}