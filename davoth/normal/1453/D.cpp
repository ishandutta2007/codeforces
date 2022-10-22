#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e3+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
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
ll n,q,e[2000],k=1;
vector<ll> an;
int main(){
    fast_io;
    e[1]=2;
    while(e[k]*2+2<=1e18){
        e[k+1]=e[k]*2+2;
        k++;
    }
    cin >> q;
    while(q--){
        cin >> n;
        an.clear();
        if(n%2==1){
            cout << -1 << '\n';
            continue;
        }
        ll j=k;
        while(n){
            //cout << j << endl;
            while(n>=e[j]){
                n-=e[j];
                an.push_back(1);
                for(ll t=1; t<j; t++) an.push_back(0);
            }
            j--;
        }
        if(an.size()>2000){
            cout << -1 << '\n';
            continue;
        }
        cout << an.size() << '\n';
        for(ll i : an) cout << i << ' ';
        cout << '\n';
    }
    //cout << e[2] << '\n';
    return 0;
}