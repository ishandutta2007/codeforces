#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
ll n,m,pw,x,y,k,h,rh,t,b=6151;
bool pf[N];
string p;
int main() {
    fast_io;
    cin >> n >> m >> p;
    pw=n;
    t=1;
    for(ll i=0; i<p.size(); i++){
        h*=b;
        h+=p[i];
        h%=MOD;
        rh+=t*p[p.size()-1-i]%MOD;
        t*=b;
        t%=MOD;
        rh%=MOD;
        if(h==rh) pf[i]=true;
    }
    if(m){
        cin >> x;
        pw-=p.size();
    }
    while(--m>0){
        y=x;
        k=y+p.size()-1;
        cin >> x;
        pw-=p.size();
        if(x>k) continue;
        pw+=(k-x+1);
        if(!pf[k-x]) return cout << 0, 0;
    }
    cout << pow(26,pw,MOD);
    return 0;
}