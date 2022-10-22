#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=320;
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
int n,m,a[N];
pair<int,int> t[N];
int main() {
    fast_io;
    cin >> n >> m;
    for(ll i=0; i<n; i++) cin >> a[i];
    t[n-1].F=1,t[n-1].S=n-1;
    for(ll i=n-2; i>=0; i--){
        if((a[i]+i)/SQ>i/SQ || a[i]+i>=n) t[i].F=1,t[i].S=i;
        else t[i].F=t[i+a[i]].F+1,t[i].S=t[i+a[i]].S;
    }
    while(m--){
        ll q;
        cin >> q;
        if(q){
            ll x,s=0;
            cin >> x;
            x--;
            while(t[x].S+a[t[x].S]<n) s+=t[x].F,x=t[x].S+a[t[x].S];
            cout << t[x].S+1 << ' ' << s+t[x].F << '\n';
        }else{
            ll x,y;
            cin >> x >> y;
            x--;
            a[x]=y;
            for(ll i=x; i>=x/SQ*SQ; i--){
                if((a[i]+i)/SQ>i/SQ || a[i]+i>=n) t[i].F=1,t[i].S=i;
                else t[i].F=t[i+a[i]].F+1,t[i].S=t[i+a[i]].S;
            }
        }
    }
    return 0;
}