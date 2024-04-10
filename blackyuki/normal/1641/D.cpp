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
const ll mod2=998244353;
const ll mod=3000000009;
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
const ll mx=1000000;
clock_t timeStart, timeFinish;
void Start() {
    timeStart=clock();
}
long double gettime() {
    return (long double)(clock()-timeStart)/(long double)(CLOCKS_PER_SEC);
}
ll V[100005][6],al[100005],srt[500005];
P sol[3200005];
ll srt2[3200005];
int main(){
    // Start();
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    rep(i,n)rep(j,m+1)cin>>V[i][j];
    rep(i,n)al[i]=V[i][m];
    sort(al,al+n);
    rep(i,n)rep(j,m)srt[i*m+j]=V[i][j];
    sort(srt,srt+n*m);
    rep(i,n){
        vi v(m);
        rep(j,m)v[j]=lower_bound(srt,srt+n*m,V[i][j])-srt+1;
        sort(all(v));
        REP(bit,1,1<<m){
            vi tmp;
            rep(j,m)if(bit>>j&1)tmp.pb(v[j]);
            ll a=0;
            rep(t,tmp.size())a=a*mx+tmp[t];
            sol[i*((1<<m)-1)+bit-1]={a*2+tmp.size()%2,V[i][m]};
        }
    }
    ll M=n*((1<<m)-1);
    vvi g(M);
    sort(sol,sol+M);
    ll l=0;
    rep(i,M){
        while(l<M-1&&sol[l].fi<sol[i].fi)l++;
        g[l].pb(sol[i].se);
    }
    vi tmp;
    rep(i,M)if(g[i].size())tmp.pb(i);
    ll ok=INF*2,ng=-1;
    while(ok-ng>1){
        ll md=(ok+ng)/2;
        ll cnt=0;
        for(ll i:tmp){
            ll idx=g[i].size()-1;
            rep(j,g[i].size()){
                while(idx>=0&&g[i][idx]+g[i][j]>md)idx--;
                if(idx<=j)break;
                if(sol[i].fi%2)cnt+=idx-j;
                else cnt-=idx-j;
            }
        }
        ll idx=n-1;
        rep(i,n){
            while(idx>=0&&al[idx]+al[i]>md)idx--;
            if(idx<=i)break;
            cnt-=idx-i;
        }
        if(cnt<0)ok=md;
        else ng=md;
    }
    if(ok==INF*2)out(-1);
    else out(ok);
    // out(gettime());
}