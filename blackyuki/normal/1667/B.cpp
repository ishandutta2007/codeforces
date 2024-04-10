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
const ll mod=1000000007;
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
    vi seg;ll n;
public:
    ll g=-inf;
    ll f(ll a,ll b){
        return max(a,b);
    }
    bool comp(ll x,ll cur){
        return x>=cur;
    }
    segtree(ll n_,ll k):n(n_){
        seg=vi(n*2,g);
        rep(i,n)seg[i+n]=k;
        for(ll i=n-1;i>0;i--)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    segtree(vi v):n(v.size()){
        seg=vi(n*2,g);
        rep(i,n)seg[i+n]=v[i];
        for(ll i=n-1;i>0;i--)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    void add(ll i,ll x){
        i+=n;seg[i]+=x;
        for(i>>=1;i>0;i>>=1)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    void update(ll i,ll x){
        i+=n;chmax(seg[i],x);
        for(i>>=1;i>0;i>>=1)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    ll get(ll l,ll r){
        ll resl=g,resr=g;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)resl=f(resl,seg[l++]);
            if(r&1)resr=f(seg[--r],resr);
        }
        return f(resl,resr);
    }
    ll solve(ll l,ll x){ //comp(x,f([l,r])) == true r
        ll cur=g;
        for(l+=n;l;l>>=1)if(l&1){
            if(comp(x,f(cur,seg[l])))break;
            cur=f(cur,seg[l++]);
        }
        if(l==0)return n;
        while(l<n){
            l<<=1;
            if(!comp(x,f(cur,seg[l])))cur=f(cur,seg[l++]);
        }
        return l-n;
    }
    void debug(ll n){
        rep(i,n)cout<<' '<<seg[i+n];cout<<endl;
    }
};
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll t;cin>>t;
    rep(tt,t){
    ll n;cin>>n;
    vi v(n+1);rep(i,n)cin>>v[i+1];
    rep(i,n)v[i+1]+=v[i];
    vi srt=v;
    dupli(srt);
    segtree seg(srt.size(),-inf);
    seg.update(lb(srt,v[n]),n);
    vi dp(n+1);
    for(int i=n-1;i>=0;i--){
        if(v[i]==v[i+1])dp[i]=dp[i+1];
        else dp[i]=dp[i+1]-1;
        ll l=lb(srt,v[i]);
        chmax(dp[i],seg.get(l+1,srt.size())-i);
        seg.update(l,dp[i]+i);
    }
    // outv(dp);
    out(dp[0]);
    }
}