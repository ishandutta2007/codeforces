#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=1e5+10,SQ=350,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll q,last;
map<ll,ll> P,X;
ll gp(ll x){
    if(P[x]){
        ll t=P[x];
        P[x]=gp(P[x]);
        X[x]^=X[t];
        return P[x];
    }
    return x;
}
void uni(ll v, ll u, ll w){
    ll pv=gp(v),pu=gp(u);
    if(pv==pu) return;
    P[pu]=pv;
    X[pu]=(w^X[v]^X[u]);
}
int main(){
    fast_io;
    cin >> q;
    while(q--){
        ll t,l,r,x;
        cin >> t >> l >> r;
        l^=last;
        r^=last;
        if(l>r) swap(l,r);
        l+=2;
        r+=3;
        if(t==1){
            cin >> x;
            x^=last;
            uni(l,r,x);
        }else{
            if(gp(l)!=gp(r)) last=1,x=-1;
            else{
                last=x=(X[l]^X[r]);
            }
            cout << x << '\n';
        }
    }
    return 0;
}