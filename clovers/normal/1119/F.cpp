/*
the vast starry sky,
bright for those who chase the light.
*/
// #include "roads.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
const int N=250005;
typedef vector<int> vec;
int n,deg[N],vis[N],bl[N];
vector<int> seq[N],used;
vector<pii> v[N],G[N];
struct node{int id; ll pre,now;};
vector<node> rep;
ll dp[N][2],sum[N];
multiset<ll> st[N],st2[N];
void dfs(int u,int f,int k){
    vis[u]=1; dp[u][0]=0;
    int num=deg[u]-k;
    for(auto &e : v[u]) if(e.first!=f){
        int to=e.first,w=e.second;
        dfs(to,u,k);
        dp[u][0]+=dp[to][0]; ll delta=dp[to][1]+w-dp[to][0];
        // if(k==1) out(to),out(w),out(dp[to][0]),out(dp[to][1]),outln(delta);
        if(sz(st[u])<num) rep.push_back({u,-inf,delta}),st[u].insert(delta),sum[u]+=delta;
        else{
            auto it=st[u].end(); it--;
            if((*it)>delta&&(*it)>0){
                sum[u]+=delta; sum[u]-=(*it);
                rep.push_back({u,*it,delta});
                st[u].erase(it); st[u].insert(delta);
            }
            else if(delta<0) dp[u][0]+=delta;
        }
    }
    dp[u][0]+=sum[u]; dp[u][1]=dp[u][0]-max(0ll,*(--st[u].end()));
}

vector<long long> minimum_closure_costs(int N,vec U,vec V,vec W){
    n=N; memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) v[i].clear();
    vector<long long> ans; ans.resize(n);
    for(int i=0;i<n-1;i++){
        U[i]++; V[i]++;
        G[U[i]].push_back(mk(V[i],W[i]));
        G[V[i]].push_back(mk(U[i],W[i]));
        deg[U[i]]++; deg[V[i]]++; ans[0]+=W[i];
    }
    for(int i=1;i<=n;i++) seq[deg[i]].push_back(i);
    for(int k=n-1;k>=1;k--){
        rep.clear();
        for(auto &u : used) if(!vis[u]) dfs(u,-1,k),ans[k]+=dp[u][0];
        reverse(rep.begin(),rep.end());
        for(auto &u : rep){
            // if(k==2) out(u.id),out(u.pre),outln(u.now);
            if(u.now!=-inf) st[u.id].erase(st[u.id].lower_bound(u.now)),sum[u.id]-=u.now;
            if(u.pre!=-inf) st[u.id].insert(u.pre),sum[u.id]+=u.pre;
        }
        for(auto &u : used) vis[u]=0;
        for(auto &u : seq[k]){
            used.push_back(u); bl[u]=1;
            for(auto &e : G[u]){
                int to=e.first,w=e.second;
                if(bl[to]){
                    v[u].push_back(e),v[to].push_back(mk(u,w));
                    auto it=st[to].lower_bound(w);
                    if(it==st[to].end()||(*it)!=w) st2[to].erase(st2[to].lower_bound(w));
                    else sum[to]-=(*it),st[to].erase(it);
                }
                else st2[u].insert(w);
            }
        }
        // outln(k);
        for(auto &u : used){
            int num=deg[u]-k+1;
            while(sz(st[u])<num&&!st2[u].empty()){
                auto it=st2[u].begin(); sum[u]+=(*it);
                st[u].insert(*it); st2[u].erase(it);
            } 
            // out(u); outln(sum[u]);
            // for(auto &to : st[u]) out(to); puts("");
        }
    }
    return ans;
}

int main(){
    int n; vector<int> U,V,W;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,z; scanf("%d%d%d",&x,&y,&z);
        U.push_back(x-1); V.push_back(y-1); W.push_back(z);
    }
    vector<ll> ans=minimum_closure_costs(n,U,V,W);
    for(auto &u : ans) printf("%lld ",u);
    return 0;
}