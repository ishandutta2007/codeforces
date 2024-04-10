#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define pb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define ub(v,k) (upper_bound(all(v),(k))-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const ll INF=1001001001;
// const ll mod=1000000007;
ll mod;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
vi fac,finv,inv;
void init(ll n){
    n*=3;
    fac=vi(n+5);finv=vi(n+5);inv=vi(n+5);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    REP(i,2,n+5){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
long long modcom(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    ll n,m,x;cin>>n>>m>>x;
    vi v(n);rep(i,n)cin>>v[i];
    vvp g(n);
    queue<ll> que;
    vp edge(m);
    PQ(P) pq;rep(i,n)pq.push(P(v[i],i));
    rep(i,m){
        ll a,b;cin>>a>>b;a--;b--;
        g[a].pb(b,i);g[b].pb(a,i);
        edge[i]=P(a,b);
    }
    ll sum=0;rep(i,n)sum+=v[i];
    if(sum<x*(n-1))dame("NO");
    out("YES");
    vi par(n,-1);
    function<ll(ll)> root=[&](ll i){
        if(par[i]==-1)return i;
        return root(par[i]);
    };
    vi ans;
    rep(i,n-1){
        auto t=pq.top();pq.pop();
        // outp(t);
        if(par[t.se]!=-1||v[t.se]!=t.fi){
            i--;continue;
        }
        while(root(g[t.se].back().fi)==t.se)g[t.se].pop_back();
        ans.pb(g[t.se].back().se+1);
        ll a=root(g[t.se].back().fi);
        ll b=t.se;
        if(g[a].size()<g[b].size())swap(a,b);
        par[b]=a;
        for(auto k:g[b])g[a].pb(k);
        v[a]=v[a]+v[b]-x;
        pq.push(P(v[a],a));
    }
    for(ll k:ans)out(k);
}