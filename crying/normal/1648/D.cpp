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
const ll MAXN=5e5+10,INF=1e17;
int n,q,a[4][MAXN];
int st[MAXN],top;
ll dp[MAXN];
ll sum[4][MAXN],l[MAXN],r[MAXN],k[MAXN],ans=-INF;
ll pre[MAXN],suf[MAXN];
vector<array<ll,2>>occ[MAXN];
struct Seg{
    ll maxn[MAXN<<2],tag[MAXN<<2];
    void pushup(int x){
        maxn[x]=max(maxn[lc(x)],maxn[rc(x)]);
    }
    void pushdown(int x){
        if(!tag[x])return;
        maxn[lc(x)]+=tag[x];maxn[rc(x)]+=tag[x];
        tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];
        tag[x]=0;
    }
    void build(int x,int l,int r){
        maxn[x]=-INF;tag[x]=0;
        if(l==r)return;int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
    void upd(int x,int l,int r,int pos,ll val){
        if(l==r){maxn[x]=val;return;}
        int mid=(l+r)>>1;pushdown(x);
        if(pos<=mid)upd(lc(x),l,mid,pos,val);
        else upd(rc(x),mid+1,r,pos,val);
        pushup(x);
    }
    void upd2(int x,int l,int r,int ql,int qr,ll val){
        if(ql<=l&&qr>=r){
            maxn[x]+=val;tag[x]+=val;return;
        }
        int mid=(l+r)>>1;pushdown(x);
        if(ql<=mid)upd2(lc(x),l,mid,ql,qr,val);
        if(qr>mid)upd2(rc(x),mid+1,r,ql,qr,val);
        pushup(x);
    }
    ll qrymax(int x,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r)return maxn[x];
        int mid=(l+r)>>1;ll ret=-INF;pushdown(x);
        if(ql<=mid)ret=max(ret,qrymax(lc(x),l,mid,ql,qr));
        if(qr>mid)ret=max(ret,qrymax(rc(x),mid+1,r,ql,qr));
        return ret;
    }
}seg,seg2;
void solve(){
    seg.build(1,1,n);seg2.build(1,1,n);
    rep(i,1,n)seg2.upd(1,1,n,i,pre[i]);
    rep(i,1,n){
        ll& ret=dp[i];ret=-INF;
        for(auto p:occ[i]){
            ll L=p[0],cost=p[1];
            ret=max(ret,seg2.qrymax(1,1,n,L,i)-cost);
            if(i==1)continue;
            ret=max(ret,seg.qrymax(1,1,n,((L==1)?L:L-1),i-1)-cost);
        }
        seg.upd(1,1,n,i,ret);
    }
    seg.build(1,1,n);seg2.build(1,1,n);
    rep(i,1,n)seg.upd(1,1,n,i,pre[i]),seg2.upd(1,1,n,i,dp[i]);
    top=0;
    rep(i,1,n){
        while(top&&suf[st[top]]<suf[i]){
            seg.upd2(1,1,n,st[top-1]+1,st[top],-suf[st[top]]);
            seg2.upd2(1,1,n,st[top-1]+1,st[top],-suf[st[top]]);
            top--;
        }
        seg.upd2(1,1,n,st[top]+1,i,suf[i]);seg2.upd2(1,1,n,st[top]+1,i,suf[i]);
        st[++top]=i;
        for(auto p:occ[i]){
            ll L=p[0],cost=p[1],val;
            val=seg.qrymax(1,1,n,L,i);
            ans=max(ans,val-cost);
            if(i==1)continue;
            val=seg2.qrymax(1,1,n,((L==1)?L:L-1),i-1);
            ans=max(ans,val-cost);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,3)rep(j,1,n)cin>>a[i][j],sum[i][j]=a[i][j]+sum[i][j-1];
    rep(i,1,q){
        cin>>l[i]>>r[i]>>k[i];
        occ[r[i]].push_back({l[i],k[i]});
    }
    rep(i,1,n)pre[i]=sum[1][i]-sum[2][i-1],suf[i]=sum[2][i]+sum[3][n]-sum[3][i-1];
    solve();
    cout<<ans;
    return 0;
}