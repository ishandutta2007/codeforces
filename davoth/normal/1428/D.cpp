#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550,M=3e5+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n,a[N],k;
vector<pll> v;
stack<pll> st,st2;
int main(){
    fast_io;
    cin >> n;
    k=n-1;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=n-1; i>=0; i--){
        if(a[i]==0) continue;
        else if(a[i]==1){
            st.push({i,k});
            v.emplace_back(i,k--);
        }else if(a[i]==2){
            if(st.empty()){
                cout << -1 << '\n';
                return 0;
            }
            ll f=st.top().S;
            v.emplace_back(i,st.top().S);
            st.pop();
            st2.push({i,f});
        }else{
            if(st.empty() && st2.empty()){
                cout << -1 << '\n';
                return 0;
            }
            if(st2.empty()){
                v.emplace_back(i,k);
                v.emplace_back(st.top().F,k);
                st.pop();
            }else{
                v.emplace_back(i,k);
                v.emplace_back(st2.top().F,k);
                st2.pop();
            }
            st2.push({i,k--});
        }
    }
    cout << v.size() << '\n';
    for(pll p : v){
        cout << p.S+1 << ' ' << p.F+1 << '\n';
    }
    return 0;
}