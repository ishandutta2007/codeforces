#include <bits/stdc++.h>
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = /*long long*/ int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=30,M=1e6+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t,a[N];
vector<ll> pr[M];
map<ll,ll> b;
int main(){
    fast_io;
    for(ll i=2; i<M; i++){
        if(pr[i].size()) continue;
        for(ll j=i; j<M; j+=i){
            pr[j].pb(i);
        }
    }
    cin >> t;
    while(t--){
        ll n,q,m1=0,m2=0,c=0;
        cin >> n;
        b.clear();
        for(ll i=0; i<n; i++){
            cin >> a[i];
            ll x=a[i],y=1;
            for(ll p : pr[a[i]]){
                ll g=0;
                while(x%p==0) x/=p,g++;
                if(g%2) y*=p;
            }
            a[i]=y;
            b[a[i]]++;
            m1=max(b[a[i]],m1);
        }
        cin >> q;
        m2=m1;
        if(b[1]%2==1) c=b[1];
        for(auto p : b){
            if(p.S%2==0) c+=p.S;
        }
        m2=max(m2,c);
        while(q--){
            long long int w;
            cin >> w;
            if(w==0) cout << m1 << '\n';
            else cout << m2 << '\n';
        }
    }
    return 0;
}