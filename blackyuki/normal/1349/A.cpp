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
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}
vi sosuu(ll n){   //n
    vector<bool> b(n-1,true);
    for(ll i=2;i<=sqrt(n);i++){
        if(!b[i-2])continue;
        for(ll j=2;i*j<=n;j++)b[i*j-2]=false;
    }
    vi res;
    rep(i,n-1)if(b[i])res.pb(i+2);
    return res;
}
bool is_prime(ll n){
    if(n<=1)return false;
    REP(i,2,sqrt(n)+1)if(n%i==0)return false;
    return true;
}
vi x;
vvi ans;
void bunkai(ll n){
    if(n<=1)return;
    for(ll i:x){
        if(i*i>n)break;
        if(n%i!=0)continue;
        ll k=0;
        while(n%i==0){
            k++;
            n/=i;
        }
        ans[i].eb(k);
    }
    if(n!=1)ans[n].eb(1);
}
int main(){
    ll n;cin>>n;
    vi v(n);
    rep(i,n)cin>>v[i];
    x=sosuu(200005);
    ans=vvi(200005);
    rep(i,n)bunkai(v[i]);
    ll res=1;
    rep(i,200005){
        if(ans[i].size()>=n-1){
            sort(all(ans[i]));reverse(all(ans[i]));
            rep(k,ans[i][n-2])res*=i;
        }
    }
    out(res);
}