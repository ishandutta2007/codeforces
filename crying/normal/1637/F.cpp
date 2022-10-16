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
const ll MAXN=2e5+10,INF=1e16;
ll n,h[MAXN];
ll ans;
vector<int>e[MAXN];
ll dfs(int u,int fa){
    ll max1=0,max2=0;
    for(auto v:e[u]){
        if(v==fa)continue;
        ll val=dfs(v,u);
        if(val>max1)max2=max1,max1=val;
        else if(val>max2)max2=val;
    }
    if(max1==0){ans+=h[u];return h[u];}
    if(fa==0){
        ans+=max(0ll,h[u]-max1)+max(0ll,h[u]-max2);
    }else{
        ll val=max(0ll,h[u]-max1);
        max1+=val;
        ans+=val;
    }
    return max1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>h[i];
    rep(i,1,n-1){
        int u,v;cin>>u>>v;e[u].pb(v);e[v].pb(u);
    }
    int rt=0;
    rep(i,1,n)if(h[i]>h[rt])rt=i;
    dfs(rt,0);
    cout<<ans;

    return 0;
}