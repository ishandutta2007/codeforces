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
const int MAXN=2010,INF=1e9;
int T,n,ans,f[MAXN];
vector<int>e[MAXN];
void dfs(int u,int fa){
    f[u]=0;int cnt=0;
    for(auto v:e[u])if(v!=fa){
        dfs(v,u);
        f[u]+=f[v];
        if(!f[v])cnt++;
    }
    f[u]+=max(cnt-1,0);
}
void solve(){
    cin>>n;
    rep(i,1,n)e[i].clear();
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    if(n==1){
        cout<<"0\n";return;
    }
    ans=INF;
    rep(i,1,n){
        dfs(i,0);
        ans=min(ans,f[i]+1);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}