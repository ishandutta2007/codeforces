#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
class UF{
    vi dif,par,sz;
    vp memo;
public:
    UF(ll n){
        dif=vi(n);par=vi(n,-1);sz=vi(n,1);
    }
    P root(ll a){
        if(par[a]==-1)return P(a,0);
        P res=root(par[a]);
        return P(res.fi,dif[a]^res.se);
    }
    bool merge(ll a,ll b){
        P A=root(a),B=root(b);
        if(A.fi==B.fi){
            memo.pb(-1,-1);
            return A.se!=B.se;
        }
        if(sz[A.fi]<sz[B.fi]){swap(a,b);swap(A,B);}
        dif[B.fi]=A.se^B.se^1;
        memo.pb(B.fi,par[B.fi]);memo.pb(A.fi,sz[A.fi]);
        par[B.fi]=A.fi;sz[A.fi]+=sz[B.fi];
        return true;
    }
    void rollback(ll c){
        rep(i,c){
            if(memo.back().fi==-1)memo.pop_back();
            else{
                sz[memo.back().fi]=memo.back().se;memo.pop_back();
                par[memo.back().fi]=memo.back().se;memo.pop_back();
            }
        }
    }
};
int main(){
    cin.tie();cout.tie();
    ios::sync_with_stdio(false);
    ll n,m,q;cin>>n>>m>>q;
    vp edge(m);
    rep(i,m){
        ll a,b;cin>>a>>b;edge[i]=P(a-1,b-1);
    }
    UF check(n);
    ll t=-1;
    rep(i,m)if(!check.merge(edge[i].fi,edge[i].se)){
        t=i+1;break;
    }
    if(t==-1){
        rep(i,q)out("NO");
        return 0;
    }
    vi ans(m,m);
    UF uf(n);
    function<void(P,P)> dfs=[&](P l,P r){
        if(l.fi==l.se)return;
        ll i=(l.fi+l.se)/2;
        REP(j,l.fi,i)uf.merge(edge[j].fi,edge[j].se);
        for(int j=r.se;j>=0;j--){
            if(!uf.merge(edge[j].fi,edge[j].se)){
                ans[i]=j;break;
            }
        }
        uf.rollback(r.se-ans[i]+1);
        uf.merge(edge[i].fi,edge[i].se);
        dfs(P(i+1,l.se),P(ans[i],r.se));
        uf.rollback(i-l.fi+1);
        for(int j=r.se;j>ans[i];j--)uf.merge(edge[j].fi,edge[j].se);
        dfs(P(l.fi,i),P(r.fi,ans[i]));
        uf.rollback(r.se-ans[i]);
    };
    dfs(P(0,t),P(0,m-1));
    rep(qq,q){
        ll a,b;cin>>a>>b;a--;b--;
        if(ans[a]<=b)out("NO");
        else out("YES");
    }
}