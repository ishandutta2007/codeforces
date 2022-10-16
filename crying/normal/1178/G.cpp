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
const int MAXN=2e5+10,LEN=200,MAXM=MAXN/LEN+10;
int n,q,idx[MAXN],arr[MAXN],dfn[MAXN],sz[MAXN],dfntot;
ll a[MAXN],b[MAXN];
ll A[MAXN],B[MAXN],C[MAXN];
ll tag[MAXM];
vector<int>e[MAXN];
void dfs(int u,int fa){
    dfn[u]=++dfntot;sz[u]=1;
    a[u]+=a[fa];b[u]+=b[fa];
    for(auto v:e[u])dfs(v,u),sz[u]+=sz[v];
}
int LL(int x){return (x-1)*LEN+1;}
int RR(int x){return (n>=x*LEN)?(x*LEN):(n);}
bool cmp(int x,int y){return B[x]>B[y];}
struct Convex{
    vector<array<ll,2> >c;
    int cur;
    void clr(){c.clear();cur=0;}
    int check(array<ll,2> a,array<ll,2> b,array<ll,2> c){return (__int128)(b[1]-a[1])*(c[0]-b[0])<=(__int128)(c[1]-b[1])*(b[0]-a[0]);}
    int check(array<ll,2> a,array<ll,2> b,ll k){
        if(k==0)return (b[1]<=a[1]);
        return (b[1]-a[1])<=k*(b[0]-a[0]);
    }
    void push(array<ll,2> p){
        if(c.size() && c.back()[0]==p[0] && c.back()[1]>=p[1])return;
        if(c.size() && c.back()[0]==p[0])c.pop_back();
        while(c.size()>=2 && check(c[c.size()-2],c[c.size()-1],p))c.pop_back();
        c.push_back(p);cur=c.size()-1;
    }
    ll qry(ll k){
        while(cur>0 && check(c[cur-1],c[cur],k))cur--;
        return -c[cur][0]*k+c[cur][1];
    }
}convex[MAXM];
void upd_block(int idx,int L,int R,ll x){
    convex[idx].clr();
    rep(j,LL(idx),RR(idx))C[j]+=tag[idx]*B[j];
    tag[idx]=0;
    rep(j,L,R)C[j]+=x*B[j];
    //rebuild
    rep(j,LL(idx),RR(idx))convex[idx].push({-B[arr[j]],C[arr[j]]});
    per(j,RR(idx),LL(idx))convex[idx].push({B[arr[j]],-C[arr[j]]});
}
void upd(int L,int R,ll x){
    rep(j,idx[L]+1,idx[R]-1)tag[j]+=x;
    if(idx[L]==idx[R])upd_block(idx[L],L,R,x);
    else upd_block(idx[L],L,RR(idx[L]),x),upd_block(idx[R],LL(idx[R]),R,x);
}
ll qry_block(int idx,int L,int R){
    upd_block(idx,L,R,0);
    ll res=0;
    rep(j,L,R)res=max(res,abs(C[j]));
    return res;
}
ll qry(int L,int R){
    ll res=0;
    rep(j,idx[L]+1,idx[R]-1)res=max(res,convex[j].qry(tag[j]));
    if(idx[L]==idx[R])res=max(res,qry_block(idx[L],L,R));
    else res=max(res,qry_block(idx[L],L,RR(idx[L]))),res=max(res,qry_block(idx[R],LL(idx[R]),R));
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,2,n){
        int fa;cin>>fa;
        e[fa].push_back(i);
    }
    rep(i,1,n)cin>>a[i];rep(i,1,n)cin>>b[i];
    dfs(1,0);
    rep(i,1,n)A[dfn[i]]=a[i],B[dfn[i]]=b[i];
    rep(i,1,n)B[i]=abs(B[i]),C[i]=B[i]*A[i]; //constant number
    //pre-build
    for(int cur=1,i=1;cur<=n;cur+=LEN,i++){
        rep(j,cur,min(n,cur+LEN-1))idx[j]=i;
    }
    rep(i,1,n)arr[i]=i;
    rep(i,1,idx[n]){
        sort(arr+LL(i),arr+RR(i)+1,cmp);
        convex[i].clr();
        rep(j,LL(i),RR(i))convex[i].push({-B[arr[j]],C[arr[j]]});
        per(j,RR(i),LL(i))convex[i].push({B[arr[j]],-C[arr[j]]});
    }
    //solve
    rep(i,1,q){
        int op;ll v,x;
        cin>>op;
        if(op==1){
            cin>>v>>x;
            int L=dfn[v],R=dfn[v]+sz[v]-1;
            upd(L,R,x);
        }else{
            cin>>v;
            int L=dfn[v],R=dfn[v]+sz[v]-1;
            cout<<qry(L,R)<<'\n';
        }
    }
    return 0;
}