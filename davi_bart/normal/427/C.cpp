#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> c(100010),v[100010],inv[100010];
vector<bool> vis(100010);
vector<int> topo;
vector<vector<int> > comp;
int N;

void dfs(int pos){
    if(vis[pos])return;
    vis[pos]=1;
    for(int x:v[pos])dfs(x);
    topo.pb(pos);
}

void dfs1(int pos){
    if(vis[pos])return;
    vis[pos]=1;
    comp.back().pb(pos);
    for(int x:inv[pos])dfs1(x);
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)cin>>c[i];
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        inv[b].pb(a);
    }
    for(int i=0;i<N;i++){
        if(vis[i])continue;
        dfs(i);
    }
    fill(vis.begin(),vis.end(),0);
    reverse(topo.begin(),topo.end());
    for(int i=0;i<N;i++){
        if(vis[topo[i]])continue;
        comp.pb(vector<int>());
        dfs1(topo[i]);
    }
    int tot=0;
    int ans=1;
    const int mod=1e9+7;
    for(int i=0;i<comp.size();i++){
        sort(comp[i].begin(),comp[i].end(),[&](int a,int b){
            if(c[a]==c[b])return a<b;
            return c[a]<c[b];
        });
        //for(int h:comp[i])cout<<h<<" ";
        //cout<<endl;
        int k=0;
        while(k<comp[i].size() && c[comp[i][k]]==c[comp[i][0]])k++;
        tot+=c[comp[i][0]];
        ans=ans*k%mod;
    }
    cout<<tot<<" "<<ans<<endl;
}