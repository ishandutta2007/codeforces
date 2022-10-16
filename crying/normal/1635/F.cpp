#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const ll MAXN=3e5+10,INF=5e18;
ll n,m,x[MAXN],w[MAXN],ans[MAXN],L[MAXN],R[MAXN];
int st[MAXN],top;
vector<int>pos[MAXN];
vector<array<int,2>>q[MAXN];
struct Seg{
    ll t[MAXN<<2],tag[MAXN<<2];
    void pushup(int x){
        t[x]=min(t[lc(x)],t[rc(x)]);
    }
    void opt(int x,ll val){
        t[x]=min(t[x],val);
        tag[x]=min(tag[x],val);
    }
    void pushdown(int x){
        opt(lc(x),tag[x]);opt(rc(x),tag[x]);tag[x]=INF;
    }
    void upd(int x,int l,int r,int ql,int qr,ll val){
        if(ql<=l&&qr>=r){
            opt(x,val);return;
        }
        pushdown(x);int mid=(l+r)>>1;
        if(ql<=mid)upd(lc(x),l,mid,ql,qr,val);
        if(qr>mid)upd(rc(x),mid+1,r,ql,qr,val);
        pushup(x);
    }
    ll qry(int x,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r)return t[x];
        int mid=(l+r)>>1;ll ret=INF;pushdown(x);
        if(ql<=mid)ret=min(ret,qry(lc(x),l,mid,ql,qr));
        if(qr>mid)ret=min(ret,qry(rc(x),mid+1,r,ql,qr));
        pushup(x);return ret;
    }
    void build(int x,int l,int r){
        t[x]=tag[x]=INF;
        if(l==r)return;
        int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
}t;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n){cin>>x[i]>>w[i];R[i]=n+1;}
    rep(i,1,m){
        int l,r;cin>>l>>r;
        q[r].push_back({l,i});
    }
    top=0;
    rep(i,1,n){
        while(top&&w[st[top]]>w[i])top--;
        if(top)L[i]=st[top];
        st[++top]=i;
    }
    top=0;
    per(i,n,1){
        while(top&&w[st[top]]>w[i])top--;
        if(top)R[i]=st[top],pos[R[i]].push_back(i);
        st[++top]=i;
    }
    t.build(1,1,n);
    rep(i,2,n){
        if(L[i])t.upd(1,1,n,1,L[i],(x[i]-x[L[i]])*(w[i]+w[L[i]]));
        for(auto u:pos[i]){
            t.upd(1,1,n,1,u,(x[i]-x[u])*(w[u]+w[i]));
        }
        for(auto qry:q[i]){
            ans[qry[1]]=t.qry(1,1,n,qry[0],qry[0]);
        }
    }
    rep(i,1,m)cout<<ans[i]<<endl;

    return 0;
}