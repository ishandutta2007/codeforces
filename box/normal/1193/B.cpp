#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
using ll = long long;

int D[100005];
ll W[100005];
vector<int> elist[100005];
map<int,ll> dfs(int u) {
    map<int,ll>ans;
    for(int v:elist[u]){
        auto q=dfs(v);
        if(q.size() >= ans.size()) swap(q, ans);
        for(auto d:q) ans[d.first]+=d.second;
    }
    if(D[u]!=-1){
        ans[D[u]]+=W[u];auto it=next(ans.find(D[u]));
        while(it!=ans.end())
            if((it->second-=W[u])>0)break;
            else W[u]=-it->second,it=ans.erase(it);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	memset(D, -1, sizeof D);
    int n,m,k;cin>>n>>m>>k;
    iter(i,2,n+1){
        int f;cin>>f;
        elist[f].push_back(i);
    }
    rep(i,m){
        int u;cin>>u;
        cin>>D[u]>>W[u];
    }
    auto q=dfs(1);
    ll v=0;for(auto d:q)v+=d.second;
    cout<<v<<endl;
    return 0;
}