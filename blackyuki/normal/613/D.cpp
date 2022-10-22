#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define pb emplace_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define ub(v,k) (upper_bound(all(v),(k))-v.begin())
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
using vpp=vector<PP>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vvvb=vector<vvb>;
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
ll inv(ll a){return modpow(a,mod-2);}
int main(){
    ll n;cin>>n;
    vvi g(n);
    rep(i,n-1){
        ll a,b;cin>>a>>b;a--;b--;
        g[a].pb(b);g[b].pb(a);
    }
    vi par(n,-1),dep(n),in(n);
    ll c=0;
    function<void(ll,ll,ll)> dfs=[&](ll i,ll p,ll d){
        in[i]=c++;
        par[i]=p;
        dep[i]=d;
        for(ll x:g[i])if(x!=p)dfs(x,i,d+1);
    };
    dfs(0,-1,0);
    vvi table(n,vi(20));rep(i,n)table[i][0]=par[i];
    rep(j,19)rep(i,n)if(table[i][j]!=-1)table[i][j+1]=table[table[i][j]][j];
    auto lca=[&](ll a,ll b){
        if(dep[a]>dep[b])swap(a,b);
        ll dif=dep[b]-dep[a];
        rep(i,20)if(dif>>i&1)b=table[b][i];
        if(a==b)return a;
        for(int i=19;i>=0;i--)if(table[a][i]!=table[b][i]){
            a=table[a][i];b=table[b][i];
        }
        return table[a][0];
    };
    auto comp=[&](ll a,ll b){
        return in[a]<in[b];
    };
    ll q;cin>>q;
    vb use(n,false);
    vvi G(n);
    function<P(ll,ll)> DFS=[&](ll i,ll p){
        ll res=0,cnt=0;
        for(ll x:G[i])if(x!=p){
            P t=DFS(x,i);
            res+=t.fi;
            if(t.se)cnt++;
        }
        if(use[i])res+=cnt;
        else if(cnt>=2)res++;
        ll r=0;
        if(use[i]||cnt==1)r=1;
        return P(res,r);
    };
    rep(qq,q){
        ll k;cin>>k;
        vi v(k);rep(i,k)cin>>v[i];
        rep(i,k)v[i]--;
        for(ll x:v)use[x]=true;
        bool ok=true;
        for(ll x:v)if(par[x]!=-1&&use[par[x]])ok=false;
        if(!ok)out(-1);
        else{
            sort(all(v),comp);
            rep(i,k-1)v.pb(lca(v[i],v[i+1]));
            sort(all(v),comp);
            v.erase(unique(all(v)),v.end());
            rep(i,v.size()-1){
                ll a=v[i],b=v[i+1],c=lca(a,b);
                G[b].pb(c);G[c].pb(b);
            }
            // out('!');outv(v);
            // outvv(G);
            out(DFS(v[0],-1).fi);
            // out('!');
            for(ll x:v)G[x]=vi(0);
        }
        for(ll x:v)use[x]=false;
    }
}