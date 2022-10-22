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

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n;cin>>n;
    vvp sx(3),sy(3);
    rep(i,n){
        ll a,b,c;cin>>a>>b>>c;
        sx[c-1].pb(a,b);
        sy[c-1].pb(b,a);
    }
    ll ans=0;
    {
    rep(i,3)sort(all(sx[i]));
    rep(i,3)sort(all(sy[i]));
    ll ok=0,ng=n/3+1;
    while(ng-ok>1){
        ll md=(ok+ng)/2;
        vi id(3);rep(i,3)id[i]=i;
        bool able=false;
        do{
            if(able)break;
            {
                ll u=sx[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sy[id[1]][i].se>=u){
                    cnt++;
                    if(cnt==md){
                        l=sy[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sy[id[2]][i].se>=u&&sy[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
            {
                ll u=sx[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sx[id[1]][i].fi>=u){
                    cnt++;
                    if(cnt==md){
                        l=sx[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sx[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
            {
                ll u=sy[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sx[id[1]][i].se>=u){
                    cnt++;
                    if(cnt==md){
                        l=sx[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sx[id[2]][i].se>=u&&sx[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
            {
                ll u=sy[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sy[id[1]][i].fi>=u){
                    cnt++;
                    if(cnt==md){
                        l=sy[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sy[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
        }while(next_permutation(all(id)));
        if(able)ok=md;
        else ng=md;
    }
    chmax(ans,ok*3);
    }
    rep(i,3)rep(j,n/3){
        sx[i][j].fi*=-1;sx[i][j].se*=-1;
        sy[i][j].fi*=-1;sy[i][j].se*=-1;
    }
    {
    rep(i,3)sort(all(sx[i]));
    rep(i,3)sort(all(sy[i]));
    ll ok=0,ng=n/3+1;
    while(ng-ok>1){
        ll md=(ok+ng)/2;
        vi id(3);rep(i,3)id[i]=i;
        bool able=false;
        do{
            if(able)break;
            {
                ll u=sx[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sy[id[1]][i].se>=u){
                    cnt++;
                    if(cnt==md){
                        l=sy[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sy[id[2]][i].se>=u&&sy[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
            {
                ll u=sx[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sx[id[1]][i].fi>=u){
                    cnt++;
                    if(cnt==md){
                        l=sx[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sx[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
            {
                ll u=sy[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sx[id[1]][i].se>=u){
                    cnt++;
                    if(cnt==md){
                        l=sx[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sx[id[2]][i].se>=u&&sx[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
            {
                ll u=sy[id[0]][md-1].fi+1;
                ll l=inf,cnt=0,cnt2=0;
                rep(i,n/3)if(sy[id[1]][i].fi>=u){
                    cnt++;
                    if(cnt==md){
                        l=sy[id[1]][i].fi+1;
                        break;
                    }
                }
                rep(i,n/3)if(sy[id[2]][i].fi>=l)cnt2++;
                if(cnt2>=md)able=true;
            }
        }while(next_permutation(all(id)));
        if(able)ok=md;
        else ng=md;
    }
    chmax(ans,ok*3);
    }
    out(ans);
}