#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=1e9+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,Rank[N][LN],pw,P[N],sz[N],par[N],k,ans;
string S,t;
bool cmp(int x, int y){
    if(Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
    if(max(x, y)+(1<<(pw-1))>n) return x>y;
    return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}
void BuildSuffixArray(){
    for(int i=1; i<=n; i++) Rank[i][0]=S[i-1], P[i]=i;
    for(pw=1; pw<LN; pw++){
        sort(P+1, P+n+1, cmp);
        Rank[P[1]][pw]=1;
        for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
    }
}
ll LCP(int x, int y){
    int res=0;
    for(int i=LN-1; i>=0; i--) if(Rank[x][i]==Rank[y][i] && max(x,y)-1<=n){
        x+=(1<<i);
        y+=(1<<i);
        res|=(1<<i);
    }
    return res;
}
ll gp(ll v){
    return par[v]==v ? v : par[v]=gp(par[v]);
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u) return;
    sz[v]+=sz[u];
    par[u]=v;
    ans=max(ans,k*sz[v]);
}
vector<ll> ed[N];
int main(){
    fast_io;
    cin >> n >> S >> t;
    for(ll i=1; i<=n/2; i++) swap(S[i-1],S[n-i]),swap(t[i-1],t[n-i]);
    for(ll i=1; i<=n; i++){
        if(t[i-1]=='0') sz[i]=1,ans=max(ans,n-i+1);
        par[i]=i;
    }
    BuildSuffixArray();
    for(ll i=1; i<n; i++){
        ed[LCP(P[i],P[i+1])].push_back(i);
    }
    for(k=N-1; k>=1; k--){
        for(ll i : ed[k]) uni(P[i],P[i+1]);
    }
    cout << ans << '\n';
    return 0;
}