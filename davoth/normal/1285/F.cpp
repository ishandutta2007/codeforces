#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
int n,a[N],f[N],cnt[N],mul[128];
ll ans;
vector<int> d[N],g[N],st;
int lb(int x){
    return x&-x;
}
void add(int x){
    mul[0]=1;
    int k=x,c=0;
    while(k>1){
        int t=d[k][1];
        while(k%t==0) k/=t;
        mul[1<<c]=t;
        c++;
    }
    for(int i=0; i<(1<<c); i++){
        mul[i]=mul[lb(i)]*mul[i^lb(i)];
        cnt[mul[i]]++;
    }
}
void rem(int x){
    mul[0]=1;
    int k=x,c=0;
    while(k>1){
        int t=d[k][1];
        while(k%t==0) k/=t;
        mul[1<<c]=t;
        c++;
    }
    for(int i=0; i<(1<<c); i++){
        mul[i]=mul[lb(i)]*mul[i^lb(i)];
        cnt[mul[i]]--;
    }
}
int get(int x){
    mul[0]=1;
    int k=x,c=0,ans=0;
    while(k>1){
        int t=d[k][1];
        while(k%t==0) k/=t;
        mul[1<<c]=t;
        c++;
    }
    for(int i=0; i<(1<<c); i++){
        mul[i]=mul[lb(i)]*mul[i^lb(i)];
        if(__builtin_popcount(i)%2) ans-=cnt[mul[i]];
        else ans+=cnt[mul[i]];
    }
    return ans;
}
int main(){
    fast_io;
    cin >> n;
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i){
            d[j].pb(i);
        }
    }
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ans=a[i];
        if(!f[a[i]]){
            f[a[i]]=1;
            for(int j : d[a[i]]){
                g[j].pb(a[i]);
            }
        }
    }
    for(int i=1; i<N; i++){
        while(!st.empty()) rem(st.back()),st.pop_back();
        sort(g[i].begin(),g[i].end(),greater<>());
        for(int x : g[i]){
            x/=i;
            int k=get(x);
            if(k){
                while(__gcd(st.back(),x)>i || --k) rem(st.back()),st.pop_back();
                ans=max(ans,1ll*st.back()*x*i);
            }
            st.pb(x);
            add(x);
        }
    }
    cout << ans << '\n';
    return 0;
}