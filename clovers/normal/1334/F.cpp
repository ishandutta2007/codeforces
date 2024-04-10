#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
const ll inf=(ll)1e18;

struct Segment_Tree{
    ll sum[N<<2],tag[N<<2];
    void pushup(int x){
        if(sum[x<<1]==inf||sum[x<<1|1]==inf) sum[x]=inf;
        else sum[x]=sum[x<<1]+sum[x<<1|1];
    }
    void build(int x,int l,int r){
        sum[x]=inf; tag[x]=0;
        if(l==r){if(l==0) sum[x]=0; else sum[x]=inf; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void pushdown(int x,int l,int mid,int r){
        if(!tag[x]) return;
        tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x];
        if(sum[x<<1]!=inf) sum[x<<1]+=tag[x]*(mid-l+1); 
        if(sum[x<<1|1]!=inf) sum[x<<1|1]+=tag[x]*(r-mid);
        tag[x]=0;
    }
    void update(int x,int l,int r,int L,int R,ll upd){
        if(L<=l&&r<=R){
            if(sum[x]!=inf) sum[x]+=(r-l+1)*upd;
            tag[x]+=upd;
            return;
        }
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=L) update(x<<1,l,mid,L,R,upd);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,upd);
        pushup(x);
    }
    void check(int x,int l,int r,int pos,ll upd){
        if(l==r) {sum[x]=min(sum[x],upd); return;}
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=pos) check(x<<1,l,mid,pos,upd);
        else check(x<<1|1,mid+1,r,pos,upd);
        pushup(x);
    }
    ll query(int x,int l,int r,int pos){
        if(l==r) return sum[x];
        int mid=(l+r)>>1; ll ret=0; pushdown(x,l,mid,r);
        if(mid>=pos) ret+=query(x<<1,l,mid,pos);
        else ret+=query(x<<1|1,mid+1,r,pos);
        return ret;
    }
}tree;
int n,a[N],p[N],b[N],m;
void print(int id){
    cout<<id<<":";
    for(int i=0;i<=m;i++) cout<<tree.query(1,0,m,i)<<" "; cout<<endl;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    tree.build(1,0,m);
    b[0]=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(b+1,b+m+1,a[i])-b;
        if(a[i]==b[pos]&&pos<=m){
            ll val=tree.query(1,0,m,pos-1);
            if(p[i]<0) tree.update(1,0,m,pos,pos,p[i]);
            if(val<inf) tree.check(1,0,m,pos,val);
            tree.update(1,0,m,0,pos-1,p[i]);
            if(p[i]<0&&pos<m) tree.update(1,0,m,pos+1,m,p[i]);
        }
        else{
            if(p[i]<0&&pos<=m) tree.update(1,0,m,pos,m,p[i]);
            tree.update(1,0,m,0,pos-1,p[i]);
        }
    }
    ll ans=tree.query(1,0,m,m);
    if(ans>=inf) puts("NO");
    else printf("YES\n%lld\n",ans);
    return 0;
}