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
const int MAXN=2e5+10,INF=1e9;
int T,n,a,b,p[MAXN],dis[MAXN];
queue<int>q;
struct Seg{
    int maxn[MAXN<<2],pos[MAXN<<2];
    void build(int x,int l,int r){
        maxn[x]=-INF;pos[x]=l;
        if(l==r)return;
        int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
    void pushup(int x){
        maxn[x]=max(maxn[lc(x)],maxn[rc(x)]);
        if(maxn[lc(x)]==maxn[x])pos[x]=pos[lc(x)];
        else pos[x]=pos[rc(x)];
    }
    void upd(int x,int l,int r,int pos,int val){
        if(l==r){
            maxn[x]=val;return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)upd(lc(x),l,mid,pos,val);
        else upd(rc(x),mid+1,r,pos,val);
        pushup(x);
    }
    void upd(array<int,2>& a,array<int,2> b){
        if(b[0]>a[0])a=b;
    }
    array<int,2> qry(int x,int l,int r,int ql,int qr){
        if(ql>qr)return {-INF,0};
        if(ql<=l && qr>=r)return {maxn[x],pos[x]};
        int mid=(l+r)>>1;array<int,2>ret={-INF,ql};
        if(ql<=mid)upd(ret,qry(lc(x),l,mid,ql,qr));
        if(qr>mid)upd(ret,qry(rc(x),mid+1,r,ql,qr));
        return ret;
    }

}seg1,seg2,seg3;
void Remove(int pos){
    seg1.upd(1,1,n,pos,-INF);
    seg2.upd(1,1,n,pos,-INF);
    seg3.upd(1,1,n,pos,-INF);
}
void Extand(int u){
    Remove(u);
    int L=max(1,u-p[u]),R=min(n,u+p[u]);
    while(1){
        auto P=seg1.qry(1,1,n,L,R);
        if(P[0]<p[u])break;
        int v=P[1];Remove(v);
        //printf("%d->%d\n",u,v);
        dis[v]=dis[u]+1;q.push(v);
    }
    while(1){
        if(u==1)break;
        auto P=seg2.qry(1,1,n,L,u-1);
        if(P[0]<u)break;
        int v=P[1];
        Remove(v);
        //printf("%d->%d\n",u,v);
        dis[v]=dis[u]+1;q.push(v);
    }
    while(1){
        if(u==n)break;
        auto P=seg3.qry(1,1,n,u+1,R);
        if(P[0]<-u)break;
        int v=P[1];Remove(v);
        //printf("%d->%d\n",u,v);
        dis[v]=dis[u]+1;q.push(v);
    }
    
}
void solve(){
    cin>>n>>a>>b;
    rep(i,1,n)cin>>p[i];
    q.push(a);dis[a]=0;
    seg1.build(1,1,n);seg2.build(1,1,n);seg3.build(1,1,n);
    rep(i,1,n)seg1.upd(1,1,n,i,p[i]);
    rep(i,1,n)seg2.upd(1,1,n,i,p[i]+i);
    rep(i,1,n)seg3.upd(1,1,n,i,p[i]-i);
    while(q.size()){
        int u=q.front();q.pop();
        Extand(u);
    }
    cout<<dis[b]<<endl;
}
int main(){
    //ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
/*
1
10 2 9
4 1 1 1 5 1 1 1 1 5
*/