#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=17,M=2e3+4,SQ=10000,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
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
ll n,a[N],q,b[100][N],m,f[100][N],d[N];
vector<ll> cv;
pair<ll,pll> qu[N];
void upd(ll c, ll t, ll x){
    t+=2;
    while(t<N) f[c][t]+=x,t+=t&-t;
}
ll get(ll c, ll t, ll x=0){
    t+=2;
    while(t) x+=f[c][t],t-=t&-t;
    return x;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        cv.pb(a[i]);
    }
    cin >> q;
    for(ll i=0; i<q; i++){
        cin >> qu[i].F >> qu[i].S.F >> qu[i].S.S;
        if(qu[i].F==1) cv.pb(qu[i].S.F);
        qu[i].S.S--;
    }
    sort(cv.begin(),cv.end());
    cv.resize(unique(cv.begin(),cv.end())-cv.begin());
    for(ll i=0; i<n; i++) a[i]=lower_bound(cv.begin(),cv.end(),a[i])-cv.begin();
    for(ll i=0; i<q; i++){
        if(qu[i].F==1) qu[i].S.F=lower_bound(cv.begin(),cv.end(),qu[i].S.F)-cv.begin();
    }
    m=cv.size();
    for(ll i=0; i<n; i++){
        for(ll j=i/SQ+1; j*SQ<n; j++) b[j][a[i]]++;
    }
    for(ll j=0; j*SQ<n; j++){
        for(ll i=0; i<m; i++){
            upd(j,b[j][i],1);
        }
    }
    for(ll i=0; i<q; i++){
        if(qu[i].F==1){
            ll k=a[qu[i].S.S];
            a[qu[i].S.S]=qu[i].S.F;
            ll t=qu[i].S.S;
            for(ll j=t/SQ+1; j*SQ<n; j++){
                upd(j,b[j][k],-1);
                b[j][k]--;
                upd(j,b[j][k],1);
                upd(j,b[j][a[t]],-1);
                b[j][a[t]]++;
                upd(j,b[j][a[t]],1);
            }
        }else{
            auto [x,y]=qu[i].S;
            if(x==1) cout << cv[a[y]] << '\n';
            else{
                x%=2;
                ll an=b[y/SQ][a[y]];
                for(ll j=y/SQ*SQ; j<=y; j++) if(a[j]==a[y]) an++;
                if(x==0) cout << an << '\n';
                else{
                    ll ans=get(y/SQ,N-5)-get(y/SQ,an-1);
                    for(ll j=y/SQ*SQ; j<=y; j++){
                        d[a[j]]++;
                        if(d[a[j]]+b[j/SQ][a[j]]==an) ans++;
                    }
                    for(ll j=y/SQ*SQ; j<=y; j++) d[a[j]]=0;
                    cout << ans << '\n';
                }
            }
        }
    }
    return 0;
}