#include<bits/stdc++.h>
#define hash dfsdfsf
using namespace std;
typedef long long ll;
typedef unsigned long long ULL;
ULL BASE = 39;
ULL MOD = 1e9 + 9;
const int maxn = 5e5 + 100;
vector<int> E[maxn];
vector<int> RE[maxn];
int n,m;
ll a[maxn];
ll sum[maxn];
ULL base[maxn];
ULL hash[maxn];
map<ULL,vector<int> > mp;
void clear(){
    for (int i=1;i<=n;i++){
        E[i].clear();
        RE[i].clear();
        sum[i] = 0;
        a[i] = 0;
        hash[i] = 0;
    }
    mp.clear();
}

void solve(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        RE[v].push_back(u);
        sum[u] += a[v];
        hash[v] = (hash[v] + base[u]) % MOD;
    }
    ll ans = sum[1];
    for (int i=2;i<=n;i++){
        ans = __gcd(ans,sum[i]);
    }
    for (int i=1;i<=n;i++){
        mp[hash[i]].push_back(i);
    }
    for (auto &pr : mp){
        ll temp = 0;
        for (int u : pr.second){
            temp += a[u];
        }
        for (int u : RE[pr.second.front()]){
            ans = __gcd(ans,sum[u] - temp);
        }
    }
    printf("%lld\n",ans);
    clear();
}
int main(){
    base[0] = 1;
    for (int i=1;i<maxn;i++){
        base[i] = base[i-1] * BASE % MOD;
    }
    int T;
    for (scanf("%d",&T);T;T--){
        solve();
    }
    return 0;
}