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
const ll mod=998244353;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
template<class T> class sparsetablema{
    ll lg=1;
    T g=-inf;
    T f(T a,T b){return max(a,b);}
    vi rng;
    vector<vector<T>> table;
public:
    sparsetablema(vector<T> v){
        while((1<<lg)<v.size())lg++;
        rng.resize(v.size()+1);
        rep(c,lg)REP(i,1<<c,1<<(c+1))if(i<=v.size())rng[i]=c;
        table=vector<vector<T>>(lg,vector<T>(v.size()));
        rep(i,v.size())table[0][i]=v[i];
        rep(c,lg-1)rep(i,v.size())if(i+(1<<c)<v.size())table[c+1][i]=f(table[c][i],table[c][i+(1<<c)]);
    }
    T get(ll l,ll r){
        if(l>=r)return g;
        return f(table[rng[r-l]][l],table[rng[r-l]][r-(1<<rng[r-l])]);
    }
};
template<class T> class sparsetablemi{
    ll lg=1;
    T g=inf;
    T f(T a,T b){return min(a,b);}
    vi rng;
    vector<vector<T>> table;
public:
    sparsetablemi(vector<T> v){
        while((1<<lg)<v.size())lg++;
        rng.resize(v.size()+1);
        rep(c,lg)REP(i,1<<c,1<<(c+1))if(i<=v.size())rng[i]=c;
        table=vector<vector<T>>(lg,vector<T>(v.size()));
        rep(i,v.size())table[0][i]=v[i];
        rep(c,lg-1)rep(i,v.size())if(i+(1<<c)<v.size())table[c+1][i]=f(table[c][i],table[c][i+(1<<c)]);
    }
    T get(ll l,ll r){
        if(l>=r)return g;
        return f(table[rng[r-l]][l],table[rng[r-l]][r-(1<<rng[r-l])]);
    }
};
ll solve(ll n,vi v){
        vi nex(n),smi,sma;
        sparsetablema<ll> spma(v);
        sparsetablemi<ll> spmi(v);
        for(int i=n-1;i>=0;i--){
            while(smi.size()&&v[smi.back()]>v[i])smi.pop_back();
            while(sma.size()&&v[sma.back()]<v[i])sma.pop_back();
            smi.pb(i);sma.pb(i);
            if(i!=n-1){
                if(v[i+1]>v[i]){
                    ll ng=sma.size(),ok=0;
                    while(ng-ok>1){
                        ll md=(ok+ng)/2;
                        if(spmi.get(i,sma[sma.size()-md-1])<v[i])ng=md;
                        else ok=md;
                    }
                    nex[i]=sma[sma.size()-ok-1];
                }
                else{
                    ll ng=smi.size(),ok=0;
                    while(ng-ok>1){
                        ll md=(ok+ng)/2;
                        if(spma.get(i,smi[smi.size()-md-1])>v[i])ng=md;
                        else ok=md;
                    }
                    nex[i]=smi[smi.size()-ok-1];
                }
            }
        }
        ll cur=0,ans=0;
        while(cur!=n-1){
            cur=nex[cur];ans++;
        }
        return ans;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    rep(tt,t){
        ll n;cin>>n;
        vi v(n);rep(i,n)cin>>v[i];
        out(solve(n,v));
    }
}