#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
ll q;
int main() {
    fast_io;
    cin >> q;
    while(q--){
        string x,y;
        ll fx=-1,fy=-1;
        cin >> x >> y;
        while(x.size()<y.size()) x='0'+x;
        while(y.size()<x.size()) y='0'+y;
        for(int i=y.size()-1; i>=0; i--) if(y[i]=='1'){
            fy=i;
            break;
        }
        if(x.size()>fy){
            for(int i=fy; i>=0; i--) if(x[i]=='1'){
                fx=i;
                break;
            }
        }
        //cout << x << ' ' << y << '\n';
        if(fx==-1) cout << 0 << '\n';
        else cout << fy-fx << '\n';
    }
    return 0;
}