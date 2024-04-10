/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=3e5+10,LN=18,M=1e6+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,k,L[N],R[N],cnt[N],f[N*4],lz[N*4],ans;
vector<pll> hs[N];
set<pair<pll,ll>> st;
void shift(ll v, ll l, ll r){
    f[v]+=lz[v]*(r-l);
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(l>=tr || tl>=r) return;
    if(l>=tl && r<=tr){
        lz[v]=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
    f[v]=f[lc]+f[rc];
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(l>=tr || tl>=r || tl>=tr) return 0;
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,tr)+get(rc,m,r,tl,tr);
}
ll check(ll x){
    memset(cnt,0,sizeof cnt);
    ll p=0,s=0,ans=0;
    for(ll i=1; i<=n; i++){
        for(auto [a,b] : hs[i]){
            cnt[a]+=b;
            if(a>=p) s+=b;
        }
        while(s-cnt[p]>=x && p<i){
            s-=cnt[p];
            p++;
        }
        ans+=p;
    }
    return ans;
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<=n; i++){
        cin >> L[i] >> R[i];
        auto it=st.lower_bound({{L[i],-1},-1});
        while(it!=st.end() && it->F.S<=R[i]){
            hs[i].pb({it->S,-(it->F.S-it->F.F)});
            it=st.erase(it);
        }
        if(it!=st.end() && it->F.F<R[i]){
            ll j=it->S,r=it->F.S;
            hs[i].pb({j,-(R[i]-it->F.F)});
            st.erase(it);
            st.insert({{R[i],r},j});
        }
        it=st.lower_bound({{L[i],-1},-1});
        if(it!=st.begin()){
            it--;
            if(it->F.S>L[i]){
                ll j=it->S,l=it->F.F,r=it->F.S;
                hs[i].pb({j,-(min(it->F.S,R[i])-L[i])});
                st.erase(it);
                st.insert({{l,L[i]},j});
                if(r>R[i]) st.insert({{R[i],r},j});
            }
        }
        st.insert({{L[i],R[i]},i});
        hs[i].pb({i,R[i]-L[i]});
    }
    ll l=0,r=inf;
    while(r-l>1){
        ll m=(l+r)>>1;
        if(check(m)>=k) l=m;
        else r=m;
    }
    memset(cnt,0,sizeof cnt);
    ll p=0,s=0;
    for(ll i=1; i<=n; i++){
        for(auto [a,b] : hs[i]){
            cnt[a]+=b;
            upd(1,1,n+1,1,a+1,b);
            if(a>=p) s+=b;
        }
        while(s-cnt[p]>=l && p<i){
            s-=cnt[p];
            p++;
        }
        ans+=get(1,1,n+1,1,p+1);
    }
    cout << ans-(check(l)-k)*l << '\n';
    return 0;
}