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
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vp v(n);rep(i,n)cin>>v[i].fi>>v[i].se;
    vvi al(m,vi(100));
    vi cnt(m);
    ll cur=0;
    vi memo(n);
    rep(i,m){
        ll t,k;cin>>t>>k;k--;
        if(t==1){
            memo[k]=i;
            if(v[k].fi+v[k].se>=100){
                for(ll j=i+v[k].fi;j<m;j+=v[k].fi+v[k].se)cnt[j]++;
                for(ll j=i+v[k].fi+v[k].se;j<m;j+=v[k].fi+v[k].se)cnt[j]--;
            }
            else{
                if(i+v[k].fi<m)al[i+v[k].fi][v[k].fi+v[k].se]++;
                if(i+v[k].fi+v[k].se<m)al[i+v[k].fi+v[k].se][v[k].fi+v[k].se]--;
            }
        }
        else{
                ll tmp=memo[k];
                tmp+=(i-tmp)/(v[k].fi+v[k].se)*(v[k].fi+v[k].se);
                if(tmp==i)tmp-=v[k].fi+v[k].se;
                if(tmp+v[k].fi>=i){
                    if(v[k].fi+v[k].se>=100){
                        for(ll j=tmp+v[k].fi;j<m;j+=v[k].fi+v[k].se)cnt[j]--;
                        for(ll j=tmp+v[k].fi+v[k].se;j<m;j+=v[k].fi+v[k].se)cnt[j]++;
                    }
                    else{
                        if(tmp+v[k].fi<m)al[tmp+v[k].fi][v[k].fi+v[k].se]--;
                        if(tmp+v[k].fi+v[k].se<m)al[tmp+v[k].fi+v[k].se][v[k].fi+v[k].se]++;
                    }
                }
                else{
                    cur--;
                    if(v[k].fi+v[k].se>=100){
                        for(ll j=tmp+v[k].fi+v[k].se;j<m;j+=v[k].fi+v[k].se)cnt[j]++;
                        for(ll j=tmp+v[k].fi+v[k].se+v[k].fi;j<m;j+=v[k].fi+v[k].se)cnt[j]--;
                    }
                    else{
                        if(tmp+v[k].fi+v[k].se<m)al[tmp+v[k].fi+v[k].se][v[k].fi+v[k].se]++;
                        if(tmp+v[k].fi+v[k].se+v[k].fi<m)al[tmp+v[k].fi+v[k].se+v[k].fi][v[k].fi+v[k].se]--;
                    }
                }
        }
        rep(j,100){
            cur+=al[i][j];
            if(i+j<m)al[i+j][j]+=al[i][j];
        }
        cur+=cnt[i];
        out(cur);
    }
}