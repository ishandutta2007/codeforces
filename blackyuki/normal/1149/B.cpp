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
typedef tuple<ll,int,int> PP;
typedef tuple<ll,ll,ll,ll> PPP;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vpp=vector<PP>;
using vvpp=vector<vpp>;
using vvvpp=vector<vvpp>;
using vvvvpp=vector<vvvpp>;
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
ll modpow(ll a,ll b,ll m){ll res=1;a%=m;while(b){if(b&1)res=res*a%m;a=a*a%m;b>>=1;}return res;}

long long dp[255][255][255];
int main() {
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    rep(i,255)rep(j,255)rep(k,255)dp[i][j][k]=n+1;
    dp[0][0][0]=0;
    vector<char> a,b,c;
    vvi nex(26,vi(n+2,n+1)),table(26);
    rep(i,n)table[s[i]-'a'].pb(i+1);
    rep(i,26)table[i].pb(n+1);
    rep(i,26)rep(j,n+1){
        nex[i][j]=table[i][lb(table[i],j+1)];
    }
    rep(qq,m){
        char t;cin>>t;
        if(t=='+'){
            ll x;cin>>x;
            char d;cin>>d;
            if(x==1){
                a.pb(d);
                ll i=a.size();
                rep(j,b.size()+1)rep(k,c.size()+1){
                    dp[i][j][k]=nex[a[i-1]-'a'][dp[i-1][j][k]];
                    if(j)chmin(dp[i][j][k],nex[b[j-1]-'a'][dp[i][j-1][k]]);
                    if(k)chmin(dp[i][j][k],nex[c[k-1]-'a'][dp[i][j][k-1]]);
                }
            }
            if(x==2){
                b.pb(d);
                ll j=b.size();
                rep(i,a.size()+1)rep(k,c.size()+1){
                    dp[i][j][k]=nex[b[j-1]-'a'][dp[i][j-1][k]];
                    if(i)chmin(dp[i][j][k],nex[a[i-1]-'a'][dp[i-1][j][k]]);
                    if(k)chmin(dp[i][j][k],nex[c[k-1]-'a'][dp[i][j][k-1]]);
                }
            }
            if(x==3){
                c.pb(d);
                ll k=c.size();
                rep(i,a.size()+1)rep(j,b.size()+1){
                    dp[i][j][k]=nex[c[k-1]-'a'][dp[i][j][k-1]];
                    if(i)chmin(dp[i][j][k],nex[a[i-1]-'a'][dp[i-1][j][k]]);
                    if(j)chmin(dp[i][j][k],nex[b[j-1]-'a'][dp[i][j-1][k]]);
                }
            }
        }
        else{
            ll x;cin>>x;
            if(x==1)a.pop_back();
            if(x==2)b.pop_back();
            if(x==3)c.pop_back();
        }
        YESNO(dp[a.size()][b.size()][c.size()]<=n);
    }
}