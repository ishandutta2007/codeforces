#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
ll MX=1000005;
vi primenumbers,f;
void initprime(){ //O(loglogMX)
    f=vi(MX+5,-1);
    vb b(MX-1,true);
    for(ll i=2;i<=sqrt(MX);i++)if(b[i-2]){
        for(ll j=2;i*j<=MX;j++){
            if(b[i*j-2])f[i*j]=i;
            b[i*j-2]=false;
        }
    }
    rep(i,MX-1)if(b[i])primenumbers.pb(i+2);
}
bool is_prime(ll n){
    if(n<=1)return false;
    REP(i,2,sqrt(n)+1)if(n%i==0)return false;
    return true;
}
vp fastbunkai(ll n){ //nMXO(logn), O(sqrt(n))
    vp res;
    if(n<=1)return res;
    if(n>MX){
        for(ll i:primenumbers){
            if(n%i)continue;
            res.pb(i,0);
            while(n%i==0){res.back().se++;n/=i;}
        }
    }
    else{
        while(f[n]!=-1){
            ll k=f[n];
            res.pb(k,0);
            while(n%k==0){res.back().se++;n/=k;}
        }
    }
    if(n!=1)res.eb(n,1);
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    initprime();
    ll t;cin>>t;
    vi mp(1000002),mp2(1000002);
    rep(tt,t){
        ll n;cin>>n;
        vi v(n);
        rep(i,n){
            ll a;cin>>a;
            vp res=fastbunkai(a);
            v[i]=1;
            for(auto x:res)if(x.se%2)v[i]*=x.fi;
        }
        ll ans=0;
        ll ans2=0;
        vi update,update2;
        for(ll x:v){
            mp[x]++;chmax(ans,mp[x]);
            update.pb(x);
        }
        for(ll x:update){
            if(mp[x]%2){
                mp2[x]+=mp[x];
                chmax(ans2,mp2[x]);
                update2.pb(x);
            }
            else{
                mp2[1]+=mp[x];
                chmax(ans2,mp2[1]);
            }
            mp[x]=0;
        }
        ll q;cin>>q;
        rep(qq,q){
            ll a;cin>>a;
            if(!a)out(ans);
            else out(ans2);
        }
        for(ll x:update)mp[x]=0;
        for(ll x:update2)mp2[x]=0;
        mp2[1]=0;
    }
}