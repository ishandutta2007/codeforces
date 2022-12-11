#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=1e9;
int n,m,a[N],f[N],s[N],laz[N*4];
struct node{int A,B,k;}t[N*4];
node merge(node x,node y){
    node ret;ret.k=x.k+y.k;
    ret.A=(x.A+1ll*y.A*f[x.k]+1ll*y.B*f[x.k-1])%mod;
    ret.B=(x.B+1ll*y.A*f[x.k-1]+(x.k>1?1ll*y.B*f[x.k-2]:0))%mod;
    return ret;
}
void build(int x,int l,int r){
    if(l==r){t[x].A=a[l];t[x].k=1;return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);build(x<<1|1,mid+1,r);
    t[x]=merge(t[x<<1],t[x<<1|1]);
}
void change(int x,int l,int r,int ql,int qr,int d){
    if(l>=ql&&r<=qr){
        t[x].A=(t[x].A+1ll*s[t[x].k-1]*d)%mod;
        if(t[x].k>1)t[x].B=(t[x].B+1ll*s[t[x].k-2]*d)%mod;
        (laz[x]+=d)%=mod;return;
    }
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)change(x<<1,l,mid,ql,qr,d);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,d);
    t[x]=merge(t[x<<1],t[x<<1|1]);
}
void change(int x,int l,int r,int p,int d){
    if(l==r){t[x].A=d;return;}
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(p<=mid)change(x<<1,l,mid,p,d);
    else change(x<<1|1,mid+1,r,p,d);
    t[x]=merge(t[x<<1],t[x<<1|1]);
}
node query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return t[x];
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(ql>mid)return query(x<<1|1,mid+1,r,ql,qr);
    if(qr<=mid)return query(x<<1,l,mid,ql,qr);
    return merge(query(x<<1,l,mid,ql,qr),query(x<<1|1,mid+1,r,ql,qr));
}
int main(){
    scanf("%d%d",&n,&m);f[0]=f[1]=s[0]=1;
    for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1;i<=n;i++)s[i]=(s[i-1]+f[i])%mod;
    // for(int i=0;i<=n;i++)printf("%d ",s[i]);puts("");
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1,op,x,y,z;i<=m;i++){
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)change(1,1,n,x,y);
        else if(op==2)printf("%d\n",query(1,1,n,x,y).A);
        else scanf("%d",&z),change(1,1,n,x,y,z);
    }
    return 0;
}