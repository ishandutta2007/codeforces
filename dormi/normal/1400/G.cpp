#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+2;
const ll mod=998244353;
ll fix(ll a){return ((a%mod)+mod)%mod;}
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[MAXN],inv[MAXN];
ll choose(int n, int r){
    if(n<r||r<0)return 0;
    return (fact[n]*inv[r]%mod)*inv[n-r]%mod;
}
pii arr[MAXN];
int psa[MAXN];
ll ways[41][MAXN];
pii hate[21];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
        psa[arr[i].first]++,psa[arr[i].second+1]--;
    }
    fact[0]=1,inv[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    set<int> peeps;
    for(int i=0;i<m;i++){
        cin>>hate[i].first>>hate[i].second;
        peeps.insert(hate[i].first),peeps.insert(hate[i].second);
    }
    for (int i = 1; i <= n; i++) psa[i]+=psa[i-1];
    for(int i=0;i<=sz(peeps);i++) {
        for (int j = 1; j <= n; j++) {
            ways[i][j]=fix(ways[i][j-1]+choose(psa[j]-i,j-i));
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<m);i++){
        set<int> te;
        for(int j=0;j<m;j++)if(i&(1<<j))te.insert(hate[j].first),te.insert(hate[j].second);
        int l=1,r=n;
        for(auto x:te)l=max(l,arr[x].first),r=min(r,arr[x].second);
        if(l<=r)ans=fix(ans+fix(ways[sz(te)][r]-ways[sz(te)][l-1])*ll(__builtin_popcount(i)%2?-1:1));
    }
    printf("%lli\n",ans);
    return 0;
}