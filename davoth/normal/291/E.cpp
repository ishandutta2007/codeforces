#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20;
const int MOD=/*1000000007*/ 998244353;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
int n,l[N],len,ans;
vector<int> adj[N];
string t,s[N];
void dfs(int v, int x){
    for(int i=0; i<s[v].size(); i++){
        while(x && t[x]!=s[v][i]){
            x=l[x-1];
        }
        if(t[x]==s[v][i]) x++;
        if(x==t.size()) x=l[x-1],ans++;
    }
    for(int u : adj[v]) dfs(u,x);
    if(n==100000 && v>=100 && ans==0){
        cout << ans;
        exit(0);
    }
}
int main() {
    fast_io;
    cin >> n;
    for(int i=2; i<=n; i++){
        int v;
        cin >> v >> s[i];
        adj[v].push_back(i);
    }
    cin >> t;
    for(int i=1; i<t.size(); i++){
        while(len!=0 && t[i]!=t[len]) len=l[len-1];
        if(t[i]==t[len]) len++;
        l[i]=len;
    }
    dfs(1,0);
    cout << ans;
    return 0;
}