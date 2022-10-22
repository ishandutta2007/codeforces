#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define pb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define fi first
#define se second
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
#define dame(a) {cout<<a<<endl;return 0;}
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
using vvvp=vector<vvp>;
using vb=vector<bool>;
using vvb=vector<vb>;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
const ll inf=1001001001001001001;
vi scc(vvi&g,ll&number_of_components){
    ll n=g.size();
    number_of_components=0;
    vvi rg(n);rep(i,n)for(ll x:g[i])rg[x].pb(i);
    vi topo,res(n);
    vb visited(n,false);
    function<void(ll,ll)> dfs=[&](ll i,ll md){
        visited[i]=true;
        if(md==0){
            for(ll x:g[i])if(!visited[x])dfs(x,md);
            topo.pb(i);
        }
        else{
            for(ll x:rg[i])if(!visited[x])dfs(x,md);
            res[i]=number_of_components;
        }
    };
    rep(i,n)if(!visited[i])dfs(i,0);
    reverse(all(topo));
    rep(i,n)visited[i]=false;
    for(ll i:topo)if(!visited[i]){
        dfs(i,1);
        number_of_components++;
    }
    return res;
}
int main(){
    ll n,m;cin>>n>>m;
    vi v(n);rep(i,n)cin>>v[i];rep(i,n)v[i]=1-v[i];
    vvi g(m*2);
    vvi num(n);
    rep(i,m){
        ll t;cin>>t;
        rep(j,t){
            ll a;cin>>a;
            num[a-1].pb(i);
        }
    }
    rep(i,n){
        ll a=num[i][0],b=num[i][1];
        g[a+m].pb(b+m*(v[i]^1));
        g[a].pb(b+m*v[i]);
        g[b+m].pb(a+m*(v[i]^1));
        g[b].pb(a+m*v[i]);
    }
    ll c;vi res=scc(g,c);
    rep(i,m)if(res[i]==res[i+m])dame("NO");
    out("YES");
}