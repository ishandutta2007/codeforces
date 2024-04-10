#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
vector<int> pos(400010);
vector<int> p[400010];
vector<bool> vis(400010);
const int mod=1e9+7;
void dfs(int pos){
    if(vis[pos])return;
    vis[pos]=1;
    for(int x:p[pos])dfs(x);
}
void solve(){
    int N;
    cin>>N;
    fill(vis.begin(),vis.begin()+N+4,0);
    for(int i=0;i<N+3;i++){
        p[i].clear();
    }
    for(int i=0;i<N;i++){
        int a;cin>>a;
        pos[a]=i;
    }
    for(int i=0;i<N;i++){
        int a;cin>>a;
        p[pos[a]].pb(i);
        p[i].pb(pos[a]);
    }

    int ans=1;
    for(int i=0;i<N;i++){
        if(vis[i])continue;
        ans=ans*2%mod;
        dfs(i);
    }
    cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();

}