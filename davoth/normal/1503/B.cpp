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
const int N=3e3+10,LN=20,M=5e1+1,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
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
ll n;
vector<pll> a,b;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if((i+j)%2) a.pb({i,j});
            else b.pb({i,j});
        }
    }
    for(ll t=0; t<n*n; t++){
        ll x;
        cin >> x;
        if(x!=1 && a.size()){
            cout << 1 << ' ' << a.back().F << ' ' << a.back().S << endl;
            a.pop_back();
        }else if(x!=2 && b.size()){
            cout << 2 << ' ' << b.back().F << ' ' << b.back().S << endl;
            b.pop_back();
        }else if(a.empty()){
            if(x==2) cout << 3 << ' ';
            else cout << 2 << ' ';
            cout << b.back().F << ' ' << b.back().S << endl;
            b.pop_back();
        }else{
            if(x==1) cout << 3 << ' ';
            else cout << 1 << ' ';
            cout << a.back().F << ' ' << a.back().S << endl;
            a.pop_back();
        }
    }
    return 0;
}