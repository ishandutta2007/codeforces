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
    ll t;cin>>t;
    rep(tt,t){
        ll n,m;cin>>n>>m;
        vi v(m);rep(i,m)cin>>v[i];
        ll ma=0;rep(i,m)chmax(ma,v[i]);
        REP(sz,1,inf){
            ll a=(sz/2)*((sz+1)/2),b=a,c=((sz+1)/2)*((sz+1)/2);
            if(n>a+b+c||ma>a+c)continue;
            out(sz);
            vvi memo(3);
            rep(j,m){
                if(memo[0].size()<a){
                    if(c+a-memo[0].size()<v[j]){
                        rep(k,v[j]){
                            if(memo[1].size()<b)memo[1].pb(j+1);
                            else memo[2].pb(j+1);
                        }
                    }
                    else{
                        rep(k,v[j]){
                            if(memo[0].size()<a)memo[0].pb(j+1);
                            else memo[2].pb(j+1);
                        }
                    }
                }
                else{
                    rep(k,v[j]){
                        if(memo[1].size()<b)memo[1].pb(j+1);
                        else memo[2].pb(j+1);
                    }
                }
            }
            vvi res(sz,vi(sz));
            rep(i,sz)rep(j,sz){
                rep(k,3)if(!memo[k].size())memo[k].pb(0);
                if(i%2==0&&j%2==0){
                    res[i][j]=memo[2].back();memo[2].pop_back();
                }
                if(i%2==0&&j%2==1){
                    res[i][j]=memo[1].back();memo[1].pop_back();
                }
                if(i%2==1&&j%2==0){
                    res[i][j]=memo[0].back();memo[0].pop_back();
                }
            }
            outvv(res);
            break;
        }
    }
}