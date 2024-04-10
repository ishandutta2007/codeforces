#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<int> adj[MN];
int dp[MN],depth[MN];
void dfs(int loc, int parent){
    vector<int> children;
    depth[loc]=depth[parent]+1;
    for(auto x:adj[loc]){
        if(x!=parent){
            dfs(x,loc);
            children.push_back(dp[x]);
        }
    }
    sort(children.begin(),children.end(),greater<>());
    dp[loc]=1;
    if(parent) {
        for (int i = 0; i < sz(children); i++) {
            dp[loc] = max(dp[loc], children[i] + i);
        }
    }
    else{
        dp[loc]=0;
        for (int i = 1; i < sz(children); i++) {
            dp[loc] = max(dp[loc], children[i] + i - 1);
        }
        if(sz(children))dp[loc]+=children.front();
    }
}
int ans=0;
void walkdfs(int loc, int parent, int parentdp){
    vector<pii> children;
    if(parentdp!=-1)children.push_back({parentdp,parent});
    for(auto x:adj[loc])if(x!=parent)children.push_back({dp[x],x});
    sort(children.begin(),children.end(),greater<>());
    int nodeans=0;
    for (int i = 1; i < sz(children); i++) {
        nodeans = max(nodeans, children[i].first + i - 1);
    }
    if(sz(children))nodeans+=children.front().first;
    ans=max(ans,nodeans);
    vector<int> pre,suf(sz(children));
    for(int i=0;i<sz(children);i++){
        pre.push_back(max(sz(pre)?pre.back():0,children[i].first+i));
    }
    for(int i=sz(children)-1;i>=0;i--){
        suf[i]=max((i==sz(children)-1?0:suf[i+1]+1),children[i].first);
    }
    for(int i=0;i<sz(children);i++){
        if(children[i].second!=parent){
            walkdfs(children[i].second,loc,max((i-1>=0?pre[i-1]:1),(i+1<sz(suf)?suf[i+1]+i:1)));
        }
    }
}
int query(int a){
    int ret;
    printf("? %d\n",a);
    fflush(stdout);
    cin>>ret;
    if(ret==-1)exit(0);
    return ret;
}
int simulate(int loc, int parent){
    vector<int> children;
    for(auto x:adj[loc]){
        if(x!=parent){
            children.push_back(x);
        }
    }
    if(sz(children)==0&&parent)return query(loc);
    sort(children.begin(),children.end(),[&](const auto &lhs, const auto &rhs){
        return dp[lhs]>dp[rhs];
    });
    if(parent){
        for (int i = 0; i < sz(children); i++) {
            int te=simulate(children[i],loc);
            if(depth[te]!=depth[loc])return te;
        }
        return loc;
    }
    else{
        vector<int> nodes;
        for (int i = 0; i < sz(children); i++) {
            int te=simulate(children[i],loc);
            if(depth[te]!=depth[loc]){
                nodes.push_back(te);
                if(sz(nodes)==2)break;
            }
        }
        while(sz(nodes)<2)nodes.push_back(loc);
        printf("! %d %d\n",nodes[0],nodes[1]);
        fflush(stdout);
    }
    return -1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    walkdfs(1,0,-1);
    printf("%d\n",ans);
    fflush(stdout);
    cin>>a;
    dfs(a,0);
    simulate(a,0);
    return 0;
}