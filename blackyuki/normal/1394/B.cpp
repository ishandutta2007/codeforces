#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
ll ans=0;
bitset<200005> v[45];
bool ok[45];
bool o[45][45];
vi d;
ll id(int i,int j){
    ll res=0;
    if(i)res+=i*(i+1)/2;
    return res+j;
}
ll dfs(int cnt,int j,int n){
    rep(i,cnt){
        if(!ok[id(j,i)])continue;
        d.pb(id(j,i));
        if(cnt!=1)dfs(cnt-1,j-1,n);
        else{
            bool r=true;
            rep(t,d.size()){
                rep(u,t)if(!o[min(d[t],d[u])][max(d[t],d[u])]){
                    r=false;break;
                }
                if(!r)break;
            }
            if(r)ans++;
        }
        d.pop_back();
    }
}
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vvp g(n);
    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;c--;
        g[a].pb(c,b);
    }
    rep(i,45)ok[i]=true;
    rep(i,45)rep(j,45)o[i][j]=true;
    rep(i,n)sort(all(g[i]));
    rep(i,n){
        ll t=g[i].size();
        rep(j,t){
            if(v[id(t-1,j)].test(g[i][j].se))ok[id(t-1,j)]=false;
            v[id(t-1,j)].set(g[i][j].se);
        }
    }
    rep(i,45)rep(j,i)if((v[i]&v[j]).any())o[j][i]=false;
    dfs(k,k-1,n);
    out(ans);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}