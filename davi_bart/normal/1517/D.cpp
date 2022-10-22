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
vector<pair<int,int> >v[500*600];
int ans[550][550];
bool vis[550*550][30];
int memo[550*550][30];
int sol(int pos,int k){
    if(k==0)return 0;
    if(vis[pos][k])return memo[pos][k];
    vis[pos][k]=1;
    int mi=1e17;
    for(auto [a,b]:v[pos]){
        mi=min(mi,sol(a,k-1)+b);
    }
    return memo[pos][k]=mi;
}
void solve(){
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M-1;j++){
            int a;
            cin>>a;
            v[i*500+j].pb({i*500+j+1,a});
            v[i*500+j+1].pb({i*500+j,a});
        }
    }  
    for(int i=0;i<N-1;i++){
        for(int j=0;j<M;j++){
            int a;
            cin>>a;
            v[i*500+j].pb({(i+1)*500+j,a});
            v[(i+1)*500+j].pb({i*500+j,a});
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(K%2==0)ans[i][j]=sol(i*500+j,K/2)*2;
            else ans[i][j]=-1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    
}
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}