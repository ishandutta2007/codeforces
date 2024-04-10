#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10,LN=20,SQ=550,M=1e9+10;
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
ll n,m,q,a[N][N];
vector<pll> ans;
void solve(ll x, ll y){
    if(y%2==1){
        for(ll i=1; i<x; i++){
            if(a[i][y]==1){
                ans.emplace_back(i,y);
                ans.emplace_back(i,y-1);
                ans.emplace_back(i+1,y-1);
                a[i][y-1]^=1;
                a[i+1][y-1]^=1;
            }
        }
        if(a[x][y]==1){
            ans.emplace_back(x,y);
            ans.emplace_back(x,y-1);
            ans.emplace_back(x-1,y-1);
            a[x-1][y-1]^=1;
            a[x][y-1]^=1;
        }
        y--;
    }
    if(x%2==1){
        for(ll i=1; i<y; i++){
            if(a[x][i]==1){
                ans.emplace_back(x,i);
                ans.emplace_back(x-1,i);
                ans.emplace_back(x-1,i+1);
                a[x-1][i]^=1;
                a[x-1][i+1]^=1;
            }
        }
        if(a[x][y]==1){
            ans.emplace_back(x,y);
            ans.emplace_back(x-1,y);
            ans.emplace_back(x-1,y-1);
            a[x-1][y]^=1;
            a[x-1][y-1]^=1;
        }
        x--;
    }
    for(ll i=1; i<=x; i+=2){
        for(ll j=1; j<=y; j+=2){
            ll w=a[i][j],e=a[i][j+1],r=a[i+1][j],t=a[i+1][j+1];
            if(w+e+r+t==4){
                ans.emplace_back(i,j),ans.emplace_back(i+1,j),ans.emplace_back(i,j+1);
                w=e=r=0;
            }
            if(w+e+r+t==1){
                if(w==1) ans.emplace_back(i,j),ans.emplace_back(i+1,j),ans.emplace_back(i,j+1),w=0,e=r=1;
                else if(e==1) ans.emplace_back(i,j),ans.emplace_back(i+1,j+1),ans.emplace_back(i,j+1),e=0,w=t=1;
                else if(r==1) ans.emplace_back(i,j),ans.emplace_back(i+1,j),ans.emplace_back(i+1,j+1),r=0,w=t=1;
                else if(t==1) ans.emplace_back(i+1,j+1),ans.emplace_back(i+1,j),ans.emplace_back(i,j+1),t=0,e=r=1;
            }
            if(w+e+r+t==2 && w!=t){
                if(w==0) ans.emplace_back(i,j),ans.emplace_back(i+1,j),ans.emplace_back(i,j+1),w=1;
                else ans.emplace_back(i+1,j+1),ans.emplace_back(i+1,j),ans.emplace_back(i,j+1),t=1;
                e^=1;
                r^=1;
            }
            if(w+e+r+t==2 && w==t){
                if(w==1) ans.emplace_back(i,j),ans.emplace_back(i+1,j),ans.emplace_back(i,j+1),w=0,e=r=t=1;
                else ans.emplace_back(i,j),ans.emplace_back(i+1,j),ans.emplace_back(i+1,j+1),r=0,e=w=t=1;
            }
            if(w+e+r+t==3){
                if(w==0) ans.emplace_back(i,j+1),ans.emplace_back(i+1,j+1),ans.emplace_back(i+1,j);
                if(e==0) ans.emplace_back(i,j),ans.emplace_back(i+1,j+1),ans.emplace_back(i+1,j);
                if(r==0) ans.emplace_back(i,j+1),ans.emplace_back(i+1,j+1),ans.emplace_back(i,j);
                if(t==0) ans.emplace_back(i,j+1),ans.emplace_back(i,j),ans.emplace_back(i+1,j);
            }
        }
    }
}
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n >> m;
        ans.clear();
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                char c;
                cin >> c;
                a[i][j]=c-'0';
            }
        }
        solve(n,m);
        cout << ans.size()/3 << '\n';
        for(ll i=0; i<ans.size(); i+=3){
            cout << ans[i].F << ' ' << ans[i].S << ' ' << ans[i+1].F << ' ' << ans[i+1].S << ' ' << ans[i+2].F << ' ' << ans[i+2].S << '\n';
        }
    }
    return 0;
}