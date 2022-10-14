// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

ll l[200005], r[200005];
vector<int>elist[200005];

pair<ll,ll> solve(int u,int f){
    ll ans1=0,ans2=0;
    for(int v:elist[u])if(v!=f){
        auto [A1,A2]=solve(v,u);
        ans1+=max(abs(l[u]-r[v])+A2,abs(l[u]-l[v])+A1);
        ans2+=max(abs(r[u]-r[v])+A2,abs(r[u]-l[v])+A1);
    }
    return {ans1,ans2};
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;while(t--){
        int n;cin>>n;
        rep1(i,n)elist[i].clear();
        rep1(i,n)cin>>l[i]>>r[i];
        rep(i,n-1){
            int u,v;cin>>u>>v;
            elist[u].pb(v);
            elist[v].pb(u);
        }
        auto [V1,V2]=solve(1,0);
        cout<<max(V1,V2)<<endl;
        // cout<<max(solve(1,0,0),solve(1,0,1))<<endl;
    }
}