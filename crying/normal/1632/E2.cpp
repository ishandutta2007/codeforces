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
const int MAXN=3e5+10;
int n,t;
int depth[MAXN],f[MAXN],dp[MAXN];
vector<int>e[MAXN];
void dfs1(int u,int fa){
    depth[u]=f[u]=depth[fa]+1;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs1(v,u);
        f[u]=max(f[u],f[v]);
    }
}
void dfs2(int u,int fa){
    int max1=depth[u],max2=depth[u];
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs2(v,u);
        if(f[v]>max1)max2=max1,max1=f[v];
        else if(f[v]>max2)max2=f[v];
    }
    if(max2==0)return;
    dp[max2-1]=max(dp[max2-1],max1+max2-2*depth[u]);
}
void solve(){
    scanf("%d",&n);rep(i,1,n)e[i].clear(),dp[i]=0;
    rep(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);e[u].pb(v);e[v].pb(u);
    }
    depth[0]=-1;
    dfs1(1,0);
    dfs2(1,0);
    per(i,n-1,0)dp[i]=max(dp[i],dp[i+1]);
    for(int l=1,r=0;l<=n;l++){
        while(r<f[1] && (dp[r]+1)/2+l>r)r++;
        printf("%d ",r);
    }
    printf("\n");
}
int main(){
    scanf("%d",&t);
    while(t--)solve();

    return 0;
}