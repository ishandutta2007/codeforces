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
int ans[200][200];
void solve(){
    int N,M;
    cin>>N>>M;
    vector<int> v[N+10];
    bool vis[N];
    vector<pair<int,int> >best;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans[i][j]=-1;
            int a;
            cin>>a;
            best.pb({a,i});
        }
    }
    sort(best.begin(),best.end());
    for(int i=0;i<M;i++){
        ans[best[i].se][i]=best[i].fi;
    }
    for(int i=M;i<best.size();i++)v[best[i].se].pb(best[i].fi);
    for(int i=0;i<N;i++){
        int pos=0;
        for(int j=0;j<M;j++){
            if(ans[i][j]!=-1)continue;
            ans[i][j]=v[i][pos];
            pos++;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
    

}
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
}