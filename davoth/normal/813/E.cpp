#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550,M=1e6+10;
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
int n,k,q,lst;
vector<int> b[N];
unordered_map<int,int> f[N];
void update(ll l, ll r, ll x){
    while(l<N){
        ll tr=r;
        while(tr<N){
            f[l][tr]+=x;
            tr+=tr&-tr;
        }
        l+=l&-l;
    }
}
ll get(ll l, ll r, ll x=0){
    while(l){
        ll tr=r;
        while(tr){
            if(f[l].find(tr)==f[l].end()){
                tr-=tr&-tr;
                continue;
            }
            x+=f[l][tr];
            tr-=tr&-tr;
        }
        l-=l&-l;
    }
    return x;
}
int main(){
    fast_io;
    for(ll i=0; i<N; i++) f[i].max_load_factor(.4), f[i].reserve(1 << 4);
    cin >> n >> k;
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        b[x].push_back(i);
        if(b[x].size()>k){
            ll t=b[x][b[x].size()-k-1];
            update(1,i,-1);
            update(t+1,i,1);
            //cout << i << ' ' << t << '\n';
        }
    }
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        l+=lst;
        r+=lst;
        l%=n;
        l++;
        r%=n;
        r++;
        if(l>r) swap(l,r);
        lst=r-l+1+get(l,r);
        cout << lst << '\n';
    }
    //cout << get(2,4) << '\n';
    return 0;
}