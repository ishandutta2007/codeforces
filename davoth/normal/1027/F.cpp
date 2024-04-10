#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=30,SQ=550,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,t=1,k=1,e[N],m1[N],m2[N],ans,b[2*N],lst=-1;
pii a[N];
bool flag[2*N],g[N];
vector<int> adj[2*N],st;
map<int,int> mp;
void dfs(int v, int p, int x){
    //cout << v << ' ' << x << '\n';
    flag[v]=1;
    e[x]-=2;
    e[x]+=adj[v].size();
    if(v>m1[x]) m2[x]=m1[x],m1[x]=v;
    else if(v>m2[x]) m2[x]=v;
    for(ll u : adj[v]){
        if(u==p) continue;
        if(flag[u]){
            g[x]=1;
            continue;
        }
        dfs(u,v,x);
    }
}
int main(){
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i].F >> a[i].S;
        st.push_back(a[i].F);
        st.push_back(a[i].S);
    }
    sort(st.begin(),st.end());
    for(int i : st){
        if(i==lst) continue;
        mp[i]=t;
        b[t++]=i;
        lst=i;
    }
    for(int i=0; i<n; i++){
        a[i].F=mp[a[i].F];
        a[i].S=mp[a[i].S];
        adj[a[i].F].push_back(a[i].S);
        adj[a[i].S].push_back(a[i].F);
    }
    for(int i=1; i<t; i++){
        if(!flag[i]) dfs(i,0,k++);
    }
    //cout << e[1] << ' ' << c[1] << '\n';
    for(int i=1; i<k; i++){
        if(e[i]>0){
            cout << -1 << '\n';
            return 0;
        }
        if(g[i]) ans=max(m1[i],ans);
        else ans=max(m2[i],ans);
    }
    cout << b[ans] << '\n';
    return 0;
}