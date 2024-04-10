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

int main(){
    ll n,q;cin>>n>>q;
    vvi g(n);
    rep(i,n-1){
        ll a,b;cin>>a>>b;a--;b--;
        g[a].pb(b);g[b].pb(a);
    }
    vi par(n,-1),sz(n);
    vvi centree(n);
    vvi dis(20,vi(n,-1));
    vb dead(n,false);
    function<ll(ll,ll)> sub=[&](ll i,ll p){
        sz[i]=1;
        for(ll x:g[i])if(x!=p&&!dead[x])sz[i]+=sub(x,i);
        return sz[i];
    };
    function<ll(ll,ll,ll)> cen=[&](ll i,ll p,ll sz_al){
        for(ll x:g[i])if(x!=p&&!dead[x]&&sz[x]>sz_al/2)return cen(x,i,sz_al);
        return i;
    };
    auto getcen=[&](ll i,ll num){
        sub(i,-1);
        ll c=cen(i,-1,sz[i]);
        dis[num][c]=0;
        queue<ll> que;que.push(c);
        while(!que.empty()){
            auto t=que.front();que.pop();
            for(ll x:g[t])if(dis[num][x]==-1&&!dead[x]){
                que.push(x);
                dis[num][x]=dis[num][t]+1;
            }
        }
        return c;
    };
    ll root=getcen(0,0);
    queue<ll> que;que.push(root);
    vi level(n);
    vi mi(n,inf);
    while(!que.empty()){
        auto t=que.front();que.pop();
        dead[t]=true;
        for(ll x:g[t])if(!dead[x]){
            ll r=getcen(x,level[t]+1);
            level[r]=level[t]+1;
            par[r]=t;que.push(r);centree[t].pb(r);
        }
    }
    auto update=[&](ll i){
        ll x=i;
        while(x!=-1){
            chmin(mi[x],dis[level[x]][i]);
            x=par[x];
        }
    };
    // outv(par);outvv(dis);outv(level);
    auto getmi=[&](ll i){
        ll res=inf;
        ll x=i;
        while(x!=-1){
            chmin(res,dis[level[x]][i]+mi[x]);
            x=par[x];
        }
        return res;
    };
    update(0);
    // outv(par);outv(mi);outvv(dis);outv(level);
    rep(qq,q){
        ll t,v;cin>>t>>v;v--;
        if(t==1)update(v);
        else out(getmi(v));
        // outv(mi);
    }
}