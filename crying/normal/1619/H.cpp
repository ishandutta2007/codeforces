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
const int MAXN=1e5+10;
int nxt[MAXN],pre[MAXN],step[MAXN];
int n,q,p[MAXN],lim=500;
int bucket[MAXN],tot;
void upd(int x){
    tot=0;
    bucket[0]=x;
    int u=x;
    rep(j,1,lim){
        u=nxt[u];
        bucket[++tot]=u;
    }
    u=x;
    step[x]=bucket[tot];
    rep(j,1,lim){
        u=pre[u];
        step[u]=bucket[tot-j];
    }
}
void upd(int x,int y){
    int nx=nxt[y],ny=nxt[x];
    nxt[x]=nx;pre[nx]=x;
    nxt[y]=ny;pre[ny]=y;
    upd(x);upd(y);
}
int qry(int x,int k){
    int cnt=k/lim,rest=k%lim;
    int u=x;
    rep(i,1,cnt)u=step[u];
    rep(i,1,rest)u=nxt[u];
    return u;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n)cin>>p[i],nxt[i]=p[i],pre[p[i]]=i;
    rep(i,1,n){
        int u=i;
        rep(j,1,lim)u=nxt[u];
        step[i]=u;
    }
    rep(i,1,q){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            upd(x,y);
        }else{
            cout<<qry(x,y)<<endl;
        }
    }
    return 0;
}