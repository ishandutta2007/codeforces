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

int main(){
    ll n,m,K;cin>>n>>m>>K;
    if(K%2){
        vvi ans(n,vi(m,-1));
        outvv(ans);return 0;
    }
    vvi a(n,vi(m-1));rep(i,n)rep(j,m-1)cin>>a[i][j];
    vvi b(n-1,vi(m));rep(i,n-1)rep(j,m)cin>>b[i][j];
    // vvi dp(n,vi(m));
    vi dx={0,1,0,-1},dy={1,0,-1,0};
    auto cost=[&](ll x,ll y,ll k){
        if(k==0)return a[x][y];
        if(k==2)return a[x][y-1];
        if(k==1)return b[x][y];
        if(k==3)return b[x-1][y];
    };
    vvvi dp(K/2+1,vvi(n,vi(m,inf)));
    rep(i,n)rep(j,m)dp[0][i][j]=0;
    REP(k,1,K/2+1){
        rep(i,n)rep(j,m){
            if(j<m-1)chmin(dp[k][i][j],dp[k-1][i+dx[0]][j+dy[0]]+cost(i,j,0));
            if(i<n-1)chmin(dp[k][i][j],dp[k-1][i+dx[1]][j+dy[1]]+cost(i,j,1));
            if(j>0)chmin(dp[k][i][j],dp[k-1][i+dx[2]][j+dy[2]]+cost(i,j,2));
            if(i>0)chmin(dp[k][i][j],dp[k-1][i+dx[3]][j+dy[3]]+cost(i,j,3));
        }
    }
    vvi ans(n,vi(m));
    rep(i,n)rep(j,m)ans[i][j]=dp[K/2][i][j]*2;
    outvv(ans);
}