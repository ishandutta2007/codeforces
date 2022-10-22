#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<bool> vb;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=(ll)(k);i<(ll)(n);i++)
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define rosrt(a) {sort(all(a));reverse(all(a));}
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define pb emplace_back
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];};cout<<'\n';}
template<class T> void outvv(T v){for(auto x:v)outv(x);}
template<class T> void outp(T p){cout<<'('<<p.fi<<','<<p.se<<')'<<endl;}
template<class T> void outvp(T v){for(auto x:v)cout<<'('<<x.fi<<','<<x.se<<')';cout<<endl;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vp v(n);rep(i,n)cin>>v[i].fi>>v[i].se;
    ll ok=-1,ng=21;
    vi res;
    while(ng-ok>1){
        ll t=(ok+ng)/2;
        vi al;
        rep(i,n){
            al.pb(v[i].fi&((1<<t)-1));
            al.pb(v[i].se&((1<<t)-1));
        }
        dupli(al);
        vp edge(n);
        rep(i,n)edge[i]=P(lb(al,v[i].fi&((1<<t)-1)),lb(al,v[i].se&((1<<t)-1)));
        ll ver=al.size();
        vi cnt(ver);
        rep(i,n)cnt[edge[i].fi]++;
        rep(i,n)cnt[edge[i].se]++;
        bool able=true;
        rep(i,ver)if(cnt[i]&1)able=false;
        if(!able){
            ng=t;continue;
        }
        vi ans;
        vvp g(ver);
        rep(i,n){
            g[edge[i].fi].pb(edge[i].se,i);
            g[edge[i].se].pb(edge[i].fi,i);
        }
        vb used(n,false);
        function<void(ll,ll)> dfs=[&](ll i,ll e){
            while(true){
                while(g[i].size()&&used[g[i].back().se])g[i].pop_back();
                if(!g[i].size())break;
                ll to=g[i].back().fi,id=g[i].back().se;g[i].pop_back();
                used[id]=true;
                dfs(to,id);
            }
            if(e!=-1){
                if(i==edge[e].fi){ans.pb(e*2+1);ans.pb(e*2+2);}
                else{ans.pb(e*2+2);ans.pb(e*2+1);}
            }
        };dfs(0,-1);
        if(ans.size()!=n*2){
            ng=t;continue;
        }
        reverse(all(ans));
        res=ans;
        ok=t;
    }
    out(ok);
    outv(res);
}