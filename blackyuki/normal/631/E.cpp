#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define pb emplace_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define ub(v,k) (upper_bound(all(v),(k))-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
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
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
struct Line{
    ll a,b;
    Line(ll A,ll B):a(A),b(B){}
    ll get(ll x){return a*x+b;}
};
class LiChaoTree{
public:
    vi srtx;
    vector<Line> seg;
    ll N;
    LiChaoTree(vi SRTX){
        srtx=SRTX;
        dupli(srtx);
        N=1;
        while(N<srtx.size())N*=2;
        while(srtx.size()<N)srtx.pb(INF);
        seg=vector<Line>(N*2-1,Line(0,-inf));
    }
    void addline(Line t,ll k=0,ll l=0,ll r=-1){
        if(r==-1)r=N;
        ll L=srtx[l],R=srtx[r-1],MD=srtx[(l+r)/2];
        if(t.get(MD)>=seg[k].get(MD))swap(t,seg[k]);
        if(seg[k].get(L)<t.get(L))addline(t,k*2+1,l,(l+r)/2);
        else if(seg[k].get(R)<t.get(R))addline(t,k*2+2,(l+r)/2,r);
    }
    ll solve(ll x){
        ll k=lb(srtx,x)+N-1,res=seg[k].get(x);
        while(k){
            k=(k-1)/2;
            chmax(res,seg[k].get(x));
        }
        return res;
    }
};
int main(){
    ll n;cin>>n;
    vi v(n);rep(i,n)cin>>v[i];
    vi f(n+1);
    rep(i,n)f[i+1]=f[i]+v[i];
    ll ans=0;
    LiChaoTree lctl(v),lctr(v);
    rep(i,n){
        chmax(ans,lctl.solve(v[i])-v[i]*i+f[i]);
        lctl.addline(Line(i,-f[i]));
    }
    for(int i=n-1;i>=0;i--){
        chmax(ans,lctr.solve(v[i])-v[i]*i+f[i+1]);
        lctr.addline(Line(i,-f[i+1]));
    }
    // rep(i,n)rep(j,n)chmax(ans,v[i]*j-v[i]*i-f[j]+f[i]);
    rep(i,n)ans+=v[i]*(i+1);
    out(ans);
}