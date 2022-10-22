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
ll res(vector<PP> v,ll n){
    sort(all(v));
    if(!v.size())return 0;
    vi dp(n*2);
    int w=0;
    rep(i,n*2){
        if(i)chmax(dp[i],dp[i-1]);
        while(w<v.size()){
            if(get<0>(v[w])!=i)break;
            ll l,r,c;tie(r,l,c)=v[w];
            ll cur=0;if(l)cur=dp[l-1];
            chmax(dp[i],cur+c);
            w++;
        }
    }
    return dp[n*2-1];
}
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;n++;
        vector<PP> v(n);
        vi s;
        rep(i,n){
            ll a=0,b=200005;if(i!=n-1)cin>>a>>b;
            v[i]=PP(b-a,a,b);
            s.pb(a);s.pb(b);
        }
        dupli(s);
        sort(all(v));
        rep(i,n){get<2>(v[i])=lb(s,get<2>(v[i]));get<1>(v[i])=lb(s,get<1>(v[i]));}
        vi id(n,1);
        rep(i,n){
            vector<PP> t;
            rep(j,n)if(j!=i)if(get<1>(v[j])>=get<1>(v[i])&&get<2>(v[j])<=get<2>(v[i])){
                t.pb(get<2>(v[j]),get<1>(v[j]),id[j]);
            }
            id[i]+=res(t,n);
        }
        out(id[n-1]-1);
    }
}