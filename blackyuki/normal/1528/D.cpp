#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
const ll mod=998244353;
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
class segtree{
    ll N=1;
    vi seg,lazy;
    vb waiting;
    ll g=0;
    ll lazy_to_seg(ll k,ll l,ll r){
        return lazy[k]*(r-l);
    }
    ll f(ll a,ll b){
        return a+b;
    }
public:
    segtree(ll n,ll k){
        while(N<n)N*=2;
        seg=vi(N*2-1,g);lazy=vi(N*2-1);waiting=vb(N*2-1,false);
        rep(i,n)seg[i+N-1]=k;
        for(ll i=N-2;i>=0;i--)seg[i]=f(seg[i*2+1],seg[i*2+2]);
    }
    segtree(vi v){
        while(N<v.size())N*=2;
        seg=vi(N*2-1,g);lazy=vi(N*2-1);waiting=vb(N*2-1,false);
        rep(i,v.size())seg[i+N-1]=v[i];
        for(ll i=N-2;i>=0;i--)seg[i]=f(seg[i*2+1],seg[i*2+2]);
    }
    void eval(ll k,ll l,ll r){
        if(!waiting[k])return;
        seg[k]=lazy_to_seg(k,l,r);
        if(r-l>1){
            waiting[k*2+1]=true;lazy[k*2+1]=lazy[k];
            waiting[k*2+2]=true;lazy[k*2+2]=lazy[k];
        }
        waiting[k]=false;
    }
    void update(ll x,ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r==-1)r=N;
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            waiting[k]=true;lazy[k]=x;
            eval(k,l,r);
            return;
        }
        update(x,a,b,k*2+1,l,(l+r)/2);
        update(x,a,b,k*2+2,(l+r)/2,r);
        seg[k]=f(seg[k*2+1],seg[k*2+2]);
    }
    ll get(ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r==-1)r=N;
        eval(k,l,r);
        if(a<=l&&r<=b)return seg[k];
        if(r<=a||b<=l)return g;
        return f(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
    void debug(ll n){
        rep(i,n)cout<<' '<<get(i,i+1);cout<<endl;
    }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vvp g(n);
    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;g[a].pb(b,c);
    }
    vvi ans(n,vi(n));
    rep(s,n){
        vi dis(n,inf);
        vb done(n,false);
        for(auto x:g[s]){
            chmin(dis[x.fi],x.se);
        }
        while(true){
            P mi=P(inf,-1);
            rep(i,n)if(!done[i])chmin(mi,P(dis[i],i));
            if(mi.fi==inf)break;
            ll i=mi.se;
            done[i]=true;
            for(auto x:g[i])chmin(dis[(dis[i]+x.fi)%n],dis[i]+x.se);
            chmin(dis[(i+1)%n],dis[i]+1);
        }
        rep(i,n)ans[s][i]=dis[i];
    }
    rep(i,n)ans[i][i]=0;
    outvv(ans);
}