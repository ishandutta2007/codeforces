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
// const ll mod=1000000007;
const ll mod=100000;
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


int main(){
    ll n,k;cin>>n>>k;
    P cur(0,-1);ll cost=0;
    vi cnt(1000000),v(n);
    rep(i,n)cin>>v[i];
    auto add=[&](ll x){
        cost+=cnt[v[x]];
        cnt[v[x]]++;
    };
    auto del=[&](ll x){
        cost-=cnt[v[x]]-1;
        cnt[v[x]]--;
    };
    vvi table(k,vi(n));
    vvi dp(k,vi(n,inf));
    ll t;
    function<void(ll,ll,ll,ll)> sol=[&](ll l,ll r,ll a,ll b){
        if(l>=r)return;
        ll md=(l+r)/2;
        while(cur.se<md)add(++cur.se);
        while(cur.fi>min(b,md))add(--cur.fi);
        while(cur.fi<min(b,md))del(cur.fi++);
        while(cur.se>md)del(cur.se--);
        table[t][md]=min(b,md);
        dp[t][md]=dp[t-1][min(b,md)-1]+cost;
        rep(i,min(b,md)-a){
            add(--cur.fi);
            if(chmin(dp[t][md],dp[t-1][min(b,md)-2-i]+cost))table[t][md]=min(b,md)-i-1;
        }
        sol(l,md,a,table[t][md]);
        sol(md+1,r,table[t][md],b);
    };
    rep(i,n){
        add(++cur.se);
        dp[0][i]=cost;
    }
    for(t=1;t<k;t++){
        sol(t,n,t,n-1);
    }
    out(dp[k-1][n-1]);
}