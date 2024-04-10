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
class BIT{
    vi bit;ll n;
    ll sum(ll i){
        ll res=0;
        for(;i>0;i-=i&-i)res+=bit[i];
        return res%mod;
    }
public:
    BIT(ll n_):n(n_){bit=vi(n+1);}
    void add(ll i,ll x){
        for(i++;i<=n;i+=i&-i)bit[i]=(bit[i]+x)%mod;
    }
    ll get(ll a,ll b){
        if(b<=a)return 0ll;
        return sum(b)-sum(a);
    }
    ll solve(ll x){ //sum([0,r])>=x r
        if(x<=0)return -1;
        ll l=0,len=1;while(len<n)len<<=1;
        for(;len;len>>=1)if(l+len<n&&bit[l+len]<x){
            x-=bit[l+len];l+=len;
        }
        return l;
    }
};
int main(){
    ll t;cin>>t;
    rep(tt,t){
        ll n;cin>>n;
        vi v(n);rep(i,n)cin>>v[i];
        vi dpl(n),dpr(n);
        {
            vp srt(n);
            rep(i,n)srt[i]=P(v[i],-i);
            sort(all(srt));
            BIT bit(n);
            rep(i,n)srt[i].se*=-1;
            for(auto x:srt){
                dpl[x.se]=bit.get(0,x.se)+1;
                bit.add(x.se,dpl[x.se]);
            }
            reverse(all(srt));
            BIT bit2(n);
            for(auto x:srt){
                dpr[x.se]=bit2.get(x.se+1,n)+1;
                bit2.add(x.se,dpr[x.se]);
            }
        }
        vi tmp;
        vb sp(n,false);
        vvp g(n);
        for(int i=n-1;i>=0;i--){
            if(tmp.size()==0||tmp.back()<=v[i]){
                tmp.pb(v[i]);g[tmp.size()-1].pb(v[i],i);
            }
            else g[lb(tmp,v[i]+1)].pb(v[i],i);
        }
        vi dp(n);
        rep(i,n)if(g[i].size()){
            vi srt;
            for(auto x:g[i])srt.pb(x.fi);
            dupli(srt);
            BIT bit(srt.size());
            for(auto x:g[i]){
                dp[x.se]=bit.get(lb(srt,x.fi)+1,srt.size());
                if(x==g[i][0])dp[x.se]++;
                bit.add(lb(srt,x.fi),dp[x.se]);
            }
        }
        // outv(dpl);outv(dpr);outv(dp);
        ll ans=0;
        rep(i,n)ans+=dpl[i]*(dpr[i]-dp[i])%mod;
        ans%=mod;if(ans<0)ans+=mod;
        out(ans);
    }
}