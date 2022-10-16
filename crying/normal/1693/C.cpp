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
int n,m,rest[MAXN],vis[MAXN],dp[MAXN];
vector<int>e[MAXN];
struct Node{
    int u,dp;
    bool operator<(const Node& n2)const{
        return dp>n2.dp;
    }
};
priority_queue<Node>pq;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m){
        int u,v;cin>>u>>v;
        e[v].push_back(u);rest[u]++;
    }
    rep(i,1,n-1)dp[i]=INF;
    dp[n]=0;pq.push((Node){n,0});
    while(pq.size()){
        Node top=pq.top();pq.pop();
        int u=top.u;if(vis[u])continue;
        vis[u]=1;
        for(auto v:e[u]){
            if(dp[u]+rest[v]<dp[v]){
                dp[v]=dp[u]+rest[v];
                pq.push((Node){v,dp[v]});
            }
            rest[v]--;
        }
    }
    cout<<dp[1];
    return 0;
}