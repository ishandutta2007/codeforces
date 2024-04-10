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
ll ask(ll l,ll r){
    cout<<'?'<<' '<<l<<' '<<r<<endl;
    fflush(stdout);
    ll a;cin>>a;
    return a;
}
ll sol(ll k){
    ll t=sqrt(k*2);
    while(t*(t-1)/2>k)t--;
    while(t*(t-1)/2<k)t++;
    return t;
}
int main(){
    ll t;cin>>t;
    rep(tt,t){
        ll n;cin>>n;
        vvi v(n);
        rep(i,n){
            string s;cin>>s;
            for(char c:s){
                if(c>='a'&&c<='z')v[i].pb(c-'a');
                else v[i].pb(26+c-'A');
            }
        }
        vvvi tmp(n,vvi(52));
        rep(i,n)rep(j,v[i].size())tmp[i][v[i][j]].pb(j);
        vvi dp(52,vi(1<<n));
        vvp memo(52,vp(1<<n));
        vector<PP> srt;
        rep(i,52)rep(j,1<<n){
            if(tmp[0][i].size()>(j&1))srt.pb(tmp[0][i][j&1],i,j);
        }
        sort(all(srt));
        for(auto f:srt){
            ll x,i,bit;tie(x,i,bit)=f;
            bool ok=true;
            rep(j,n){
                if((bit>>j&1)>=tmp[j][i].size())ok=false;
            }
            if(!ok)continue;
            chmax(dp[i][bit],1ll);
            rep(j,52){
                ll nbit=0;
                rep(k,n){
                    ll l=0;
                    while(l<tmp[k][j].size()&&tmp[k][j][l]<=tmp[k][i][bit>>k&1])l++;
                    if(l==tmp[k][j].size()){
                        nbit=-1;break;
                    }
                    if(l)nbit+=1<<k;
                }
                if(nbit==-1)continue;
                if(chmax(dp[j][nbit],dp[i][bit]+1))memo[j][nbit]=P(i,bit);
            }
        }
        P ma=P(0,0);
        rep(i,52)rep(j,1<<n)if(dp[ma.fi][ma.se]<dp[i][j])ma=P(i,j);
        if(dp[ma.fi][ma.se]==0){
            out(0);cout<<endl;
        }
        else{
            out(dp[ma.fi][ma.se]);
            string ans;
            char c;
            if(ma.fi<26)c='a'+ma.fi;
            else c='A'+(ma.fi-26);
            ans+=c;
            while(dp[ma.fi][ma.se]!=1){
                ma=memo[ma.fi][ma.se];
                char c;
                if(ma.fi<26)c='a'+ma.fi;
                else c='A'+(ma.fi-26);
                ans=c+ans;
            }
            out(ans);
        }
    }
}