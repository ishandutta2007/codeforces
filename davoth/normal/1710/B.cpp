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
const int N=2e5+10,LN=20,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll t,n,m,a[N],b[N];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pair<pll,ll>> vec;
        vector<ll> x,ps;
        for(ll i=1; i<=n; i++){
            cin >> a[i] >> b[i];
            vec.pb({{a[i],b[i]},i});
            x.pb(a[i]);
        }
        sort(vec.begin(),vec.end());
        sort(x.begin(),x.end());
        x.resize(unique(x.begin(),x.end())-x.begin());
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll p=0,s=0,li=0;
        for(ll i : x){
            while(!pq.empty() && pq.top()<=i){
                s-=pq.top()-li;
                pq.pop();
            }
            s-=pq.size()*(i-li);
            while(p<(int)vec.size() && vec[p].F.F==i){
                pq.push(i+vec[p].F.S);
                s+=vec[p].F.S;
                p++;
            }
            ps.pb(s);
            li=i;
        }
        s=0;
        while(!pq.empty()) pq.pop();
        p=(int)vec.size()-1;
        for(ll j=(int)x.size()-1; j>=0; j--){
            ll i=x[j];
            while(!pq.empty() && pq.top()+i<=0){
                s-=pq.top()+li;
                pq.pop();
            }
            s-=pq.size()*(li-i);
            ps[j]+=s;
            while(p>=0 && vec[p].F.F==i){
                pq.push(vec[p].F.S-i);
                s+=vec[p].F.S;
                p--;
            }
            li=i;
        }
        p=0;
        ll f=-INF;
        vector<ll> ans(n+1,1);
        for(auto [P,i] : vec){
            auto [a,b] = P;
            while(p<(int)x.size() && x[p]==a){
                if(ps[p]>m) f=max(f,ps[p]-m-x[p]);
                p++;
            }
            if(b-a<f) ans[i]=0;
        }
        f=-INF;
        p=(int)x.size()-1;
        for(ll j=(int)vec.size()-1; j>=0; j--){
            auto [a,b] = vec[j].F;
            ll i=vec[j].S;
            while(p>=0 && x[p]==a){
                if(ps[p]>m) f=max(f,ps[p]-m+x[p]);
                p--;
            }
            if(b+a<f) ans[i]=0;
        }
        for(ll i=1; i<=n; i++) cout << ans[i];
        cout << '\n';
    }
    return 0;
}