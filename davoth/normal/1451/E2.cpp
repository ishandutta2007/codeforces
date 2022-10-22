#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll N=1e5+10,LN=20,SQ=550,M=5e4+10;
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
ll n,a[N],b[N],ti,tj,c[N],gi,gj,x,y;
int main(){
    fast_io;
    cin >> n;
    for(ll i=2; i<=n; i++){
        cout << "XOR " << 1 << ' ' << i << endl;
        cin >> a[i];
        if(a[i]==1) gi=i;
        if(a[i]==2) gj=i;
        if(b[a[i]]){
            ti=b[a[i]];
            tj=i;
        }else if(a[i]==0){
            ti=1,tj=i;
        }
        b[a[i]]=i;
    }
    if(ti!=0){
        cout << "AND " << ti << ' ' << tj << endl;
        cin >> c[ti];
        c[tj]=c[ti];
        for(ll i=1; i<=n; i++) c[i]=a[i]^a[ti]^c[ti];
        cout << "! ";
        for(ll i=1; i<=n; i++) cout << c[i] << ' ';
        cout << endl;
        return 0;
    }
    cout << "AND " << 1 << ' ' << gi << endl;
    cin >> x;
    cout << "AND " << 1 << ' ' << gj << endl;
    cin >> y;
    c[1]=x|y;
    for(ll i=2; i<=n; i++) c[i]=c[1]^a[i];
    cout << "! ";
    for(ll i=1; i<=n; i++) cout << c[i] << ' ';
    cout << endl;
    return 0;
}