#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=4e5+10;
int n,a[MAXN],b[MAXN],tot,ans;
int f[MAXN],g[MAXN];
struct Seg{
    int val[MAXN<<2];
    void pushup(int x){
        val[x]=max(val[lc(x)],val[rc(x)]);
    }
    void build(int x,int l,int r){
        val[x]=0;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
    void upd(int x,int l,int r,int pos,int v){
        if(l==r){
            val[x]=max(val[x],v);
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)upd(lc(x),l,mid,pos,v);
        else upd(rc(x),mid+1,r,pos,v);
        pushup(x);
    }
    int qry(int x,int l,int r,int ql,int qr){
        if(ql<=l && qr>=r)return val[x];
        int mid=(l+r)>>1;int ret=0;
        if(ql<=mid)ret=max(ret,qry(lc(x),l,mid,ql,qr));
        if(qr>mid)ret=max(ret,qry(rc(x),mid+1,r,ql,qr));
        pushup(x);return ret;
    }
}f1,f2,f3;
int dp[MAXN][2];
int main(){
    cin>>n;
    rep(i,1,n)cin>>a[i],a[i]-=i,b[++tot]=a[i],b[++tot]=(a[i]+1);
    sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;
    rep(i,1,n)a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    f1.build(1,1,tot);f2.build(1,1,tot);f3.build(1,1,tot);
    a[0]=1;
    rep(i,1,n){
        dp[i][0]=f1.qry(1,1,tot,1,a[i])+1;
        dp[i][1]=max(f2.qry(1,1,tot,1,a[i]),f3.qry(1,1,tot,1,a[i]+1))+1;
        f1.upd(1,1,tot,a[i],dp[i][0]);
        f2.upd(1,1,tot,a[i],dp[i][1]);
        f3.upd(1,1,tot,a[i-1],dp[i-1][0]+1);
        ans=max(ans,dp[i][0]+(i!=n));
        ans=max(ans,dp[i][1]);
    }
    cout<<n-ans;
    return 0;
}