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
// const ll mod=1000000007;
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
// ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}

//  mod
//  -17  5  3 (-17  3 (mod. 5))
//  -17 % 5  -2 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

//  Euclid 
// ap + bq = gcd(a, b)  (p, q) d = gcd(a, b) 
long long extGcd(long long a, long long b, long long &p, long long &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    long long d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

// 
//  (r, m)  x  r (mod. m)
//  (0, -1) 
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
  long long p, q;
  long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d); // lcm of (m1, m2)
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;cin>>n>>m>>k;
    ll t=max(n,m)*2;
    vi a(t,-1),b(t,-1);
    rep(i,n){
        ll x;cin>>x;
        a[x-1]=i;
    }
    rep(i,m){
        ll x;cin>>x;
        b[x-1]=i;
    }
    vp al;
    rep(i,t)if(a[i]!=-1&&b[i]!=-1){
        P res=ChineseRem(a[i],n,b[i],m);
        if(res.se!=-1){
            al.pb(res);
        }
    }
    ll ok=inf,ng=k-1;
    while(ok-ng>1){
        ll md=(ok+ng)/2;
        ll ans=md;
        for(auto x:al){
            ans-=md/x.se;
            if(md%x.se>x.fi)ans--;
        }
        if(ans>=k)ok=md;
        else ng=md;
    }
    out(ok);
}