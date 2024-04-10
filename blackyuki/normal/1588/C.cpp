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
#define popcnt __builtin_popcountll
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
ll ask(ll l,ll r){
    cout<<'?'<<' '<<l<<' '<<r<<endl;
    fflush(stdout);
    ll a;cin>>a;
    return a;
}
ll sol(ll k){
    ll t=sqrt(k*2);
    while(t*(t-1)/2>k)t--;
    while(t*(t-1)/2<k)t++;
    return t;
}
int main(){
    ll t;cin>>t;
    rep(tt,t){
        ll n;cin>>n;
        vi v(n);rep(i,n)cin>>v[i];
        rep(i,n)if(i%2)v[i]*=-1;
        vi rui(n+1);rep(i,n)rui[i+1]=rui[i]+v[i];
        vi memo(n);
        vvp tmp(2);
        for(int i=n-1;i>=0;i--){
            if(i%2){
                while(tmp[1].size()&&tmp[1].back().fi>=-rui[i+1])tmp[1].pop_back();
                tmp[1].pb(-rui[i+1],i);
            }
            else{
                while(tmp[0].size()&&tmp[0].back().fi>=rui[i+1])tmp[0].pop_back();
                tmp[0].pb(rui[i+1],i);
            }
            memo[i]=n-1;
            ll l=lb(tmp[0],P(rui[i],-1));
            if(l)chmin(memo[i],tmp[0][l-1].se-1);
            l=lb(tmp[1],P(-rui[i],-1));
            if(l)chmin(memo[i],tmp[1][l-1].se-1);
        }
        // outv(memo);
        vi srt=rui;
        dupli(srt);
        vvi g(srt.size());
        rep(i,n+1)g[lb(srt,rui[i])].pb(i);
        ll ans=0;
        rep(i,n){
            ans+=lb(g[lb(srt,rui[i])],memo[i]+2)-lb(g[lb(srt,rui[i])],i+1);
        }
        out(ans);
    }
}