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
const ll MAXN=3e5+10,INF=3e18;
int n,op[MAXN],x[MAXN],y[MAXN],tag[MAXN];
ll ans[MAXN];
vector<array<int,2> >node[MAXN<<2];
bool cmp(const array<int,2>p1,const array<int,2>p2){
    if(p1[0]!=p2[0])return p1[0]<p2[0];
    return p1[1]<p2[1];
}
db D(const array<int,2>p1,const array<int,2>p2){return 1.00*(p2[1]-p1[1])/(p2[0]-p1[0]);}
struct Convex{
    vector<array<int,2> >p,c;
    void insert(const array<int,2>& point){p.push_back(point);}
    void build(){
        sort(p.begin(),p.end(),cmp);
        int sz=p.size();
        rep(i,0,sz-1){
            if(i && p[i][0]==p[i-1][0])continue;
            array<int,2>Z=p[i];
            while(c.size()>=2){
                array<int,2>X=c[c.size()-2],Y=c.back();
                if(D(Y,X)>D(Z,Y))c.pop_back();
                else break;
            }
            c.push_back(Z);
        }
    }
    ll calc(ll k,ll x,ll y){return k*x-y;}
    ll qry(ll k){
        if(c.empty())return -INF;
        if(c.size()==1)return calc(k,c[0][0],c[0][1]);
        int L=0,R=c.size()-2,ret=c.size()-1;
        while(L<=R){
            int mid=(L+R)>>1;
            if(D(c[mid],c[mid+1])>k)ret=mid,R=mid-1;
            else L=mid+1;
        }
        return calc(k,c[ret][0],c[ret][1]);
    }
}convex[MAXN<<2];
void upd(int x,int l,int r,int ql,int qr,array<int,2> p){
    if(ql<=l && qr>=r)return (void)(node[x].push_back(p));
    int mid=(l+r)>>1;
    if(ql<=mid)upd(lc(x),l,mid,ql,qr,p);
    if(qr>mid)upd(rc(x),mid+1,r,ql,qr,p);
}
void build(int x,int l,int r){
    for(auto p:node[x])convex[x].insert(p);
    convex[x].build();
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc(x),l,mid);build(rc(x),mid+1,r);
}
void qry(int x,int l,int r,int pos,ll& ans,ll k){
    ans=max(ans,convex[x].qry(k));
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)qry(lc(x),l,mid,pos,ans,k);
    else qry(rc(x),mid+1,r,pos,ans,k);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n){
        cin>>op[i];
        if(op[i]==1)cin>>x[i]>>y[i];
        else cin>>x[i];
        ans[i]=-INF;
    }
    rep(i,1,n){
        if(op[i]==2){
            int j=x[i];
            upd(1,1,n,j,i,{x[j],-y[j]});
            tag[j]=1;
        }
    }
    rep(i,1,n)if(op[i]==1 && !tag[i])upd(1,1,n,i,n,{x[i],-y[i]});
    build(1,1,n);
    rep(i,1,n)if(op[i]==3){
        qry(1,1,n,i,ans[i],x[i]);
        if(ans[i]==-INF)cout<<("EMPTY SET")<<endl;
        else cout<<ans[i]<<endl;
    }
    return 0;
}