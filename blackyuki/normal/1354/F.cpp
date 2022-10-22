#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb emplace_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define dupli(a) a.erase(unique(all(a)),a.end())
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

int main(){
    ll t;cin>>t;
    rep(tt,t){
        ll n,k;cin>>n>>k;
        vp v(n);
        rep(i,n)cin>>v[i].fi>>v[i].se;
        vp s(n);
        rep(i,n)s[i]=P(v[i].se,i);
        sort(all(s));reverse(all(s));
        if(k==1){
            out(1);
            ll res=0;
            rep(i,n)chmax(res,v[i].fi);
            rep(i,n)if(v[i].fi==res){
                out(i+1);break;
            }
            continue;
        }
        vvi dp(n+1,vi(k+1,-inf));
        dp[0][0]=0;
        rep(i,n){
            ll id=s[i].se;
            rep(j,k+1){
                if(dp[i][j]==-inf)continue;
                chmax(dp[i+1][j],dp[i][j]+v[id].se*(k-1));
                if(j!=k)chmax(dp[i+1][j+1],dp[i][j]+v[id].fi+v[id].se*(k-1-j));
            }
        }
        vi ans,b;
        ll c;
        ll t=k;
        for(int i=n;i;i--){
            ll id=s[i-1].se;
            if(dp[i-1][t]+v[id].se*(k-1)==dp[i][t])b.pb(id+1);
            else{
                if(t==1)c=id+1;
                else ans.pb(id+1);
                t--;
            }
        }
        for(ll x:b){
            ans.pb(x);ans.pb(-x);
        }
        ans.pb(c);
        out(ans.size());
        outv(ans);
    }
}