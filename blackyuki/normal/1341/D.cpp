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
#define dupli(a) erase(unique(all(a)),a.end())
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=1000000007;
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
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}

int main(){
    vector<string> num={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    ll n,k;cin>>n>>k;
    vector<string> v(n);
    rep(i,n)cin>>v[i];
    vvb ok(n,vb(10,true));
    vvi cnt(n,vi(10));
    rep(i,n)rep(j,10){
        rep(t,7){
            if(v[i][t]=='1'&&num[j][t]=='0'){
                ok[i][j]=false;break;
            }
            if(v[i][t]!=num[j][t])cnt[i][j]++;
        }
    }
    vvb dp(n,vb(k+1,false));
    rep(j,10)if(ok[n-1][j])dp[n-1][cnt[n-1][j]]=true;
    for(int i=n-2;i>=0;i--){
        rep(t,k+1)if(dp[i+1][t]){
            rep(j,10){
                if(ok[i][j]&&t+cnt[i][j]<=k)dp[i][t+cnt[i][j]]=true;
            }
        }
    }
    string ans;
    if(!dp[0][k])dame(-1);
    rep(i,n-1){
        for(int j=9;j>=0;j--)if(ok[i][j]&&k-cnt[i][j]>=0){
            if(dp[i+1][k-cnt[i][j]]){
                k-=cnt[i][j];
                ans+=(char)('0'+j);
                break;
            }
        }
    }
    for(int j=9;j>=0;j--)if(ok[n-1][j]&&k==cnt[n-1][j]){
        ans+=(char)('0'+j);
        break;
    }
    out(ans);
}