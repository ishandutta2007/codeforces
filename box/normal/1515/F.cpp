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
vector<pii>elist[300005];
vector<int>fw,bw;
bool vis[300005];
int th;
ll cnt[300005];
ll dfs(int u){
    vis[u]=1;
    ll c=cnt[u];
    for(auto [x,y]:elist[u]){
        if(vis[x])continue;
        ll a=dfs(x);
        if(c+a-th>=0){
            c=c+a-th;
            fw.push_back(y);
        }else{
            bw.push_back(y);
        }
    }
    return c;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;cin>>n>>m>>th;
    ll tt=0;
    rep1(i,n){
        cin>>cnt[i];
        tt+=cnt[i];
    }
    rep1(i,m){
        int u,v;cin>>u>>v;
        elist[u].push_back({v,i});
        elist[v].push_back({u,i});
    }
    if(tt<1LL*(n-1)*th){
        cout<<"NO\n";
    }else{
        dfs(1);
        cout<<"YES\n";
        for(int i:fw)cout<<i<<endl;
        reverse(all(bw));
        for(int i:bw)cout<<i<<endl;
    }
}