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
class segtree{
    ll N=1;
    vi seg,lazy;
    vb waiting;
    ll g=-inf;
    ll lazy_to_seg(ll k,ll l,ll r){
        return lazy[k];
    }
    ll f(ll a,ll b){
        return max(a,b);
    }
public:
    segtree(ll n,ll k){
        while(N<n)N*=2;
        seg=vi(N*2-1,g);lazy=vi(N*2-1);
        rep(i,n)seg[i+N-1]=k;
        for(ll i=N-2;i>=0;i--)seg[i]=f(seg[i*2+1],seg[i*2+2]);
    }
    segtree(vi v){
        while(N<v.size())N*=2;
        seg=vi(N*2-1,g);lazy=vi(N*2-1);
        rep(i,v.size())seg[i+N-1]=v[i];
        for(ll i=N-2;i>=0;i--)seg[i]=f(seg[i*2+1],seg[i*2+2]);
    }
    void eval(ll k,ll l,ll r){
        seg[k]+=lazy_to_seg(k,l,r);
        if(r-l>1){
            lazy[k*2+1]+=lazy[k];
            lazy[k*2+2]+=lazy[k];
        }
        lazy[k]=0;
    }
    void add(ll x,ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r==-1)r=N;
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            lazy[k]+=x;
            eval(k,l,r);
            return;
        }
        add(x,a,b,k*2+1,l,(l+r)/2);
        add(x,a,b,k*2+2,(l+r)/2,r);
        seg[k]=f(seg[k*2+1],seg[k*2+2]);
    }
    ll get(ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r==-1)r=N;
        eval(k,l,r);
        if(a<=l&&r<=b)return seg[k];
        if(r<=a||b<=l)return g;
        return f(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
    void debug(ll n){
        rep(i,n)cout<<' '<<get(i,i+1);cout<<endl;
    }
};
void show(multiset<ll> s){
    auto itr=s.begin();
    while(itr!=s.end()){
        cout<<' '<<*itr;itr++;
    }
    cout<<endl;
}
inline ll readll() {
    ll res;scanf("%lld",&res);return res;
}

int main(){
    ll n,q,w;cin>>n>>q>>w;
    vp edge(n-1);
    vi cost(n-1);
    vvp g(n);
    rep(i,n-1){
        ll a=readll()-1,b=readll()-1,c=readll();
        edge[i]=P(a,b);cost[i]=c;
        g[a].pb(b,i),g[b].pb(a,i);
    }
    vb dead(n,false);
    vi sz(n);
    function<ll(ll,ll)> dfs_sz=[&](ll i,ll p){
        sz[i]=1;
        for(auto x:g[i])if(x.fi!=p&&!dead[x.fi])sz[i]+=dfs_sz(x.fi,i);
        return sz[i];
    };
    function<ll(ll,ll,ll)> find_centroid=[&](ll i,ll p,ll root){
        for(auto x:g[i])if(x.fi!=p&&!dead[x.fi]&&sz[x.fi]*2>sz[root])return find_centroid(x.fi,i,root);
        return i;
    };
    vvp range(n-1,vp(20));
    vi cnt(20);
    vvi v(20);
    vi level(n),par(n);
    vector<multiset<ll>> S(n);
    multiset<ll> al;
    function<void(ll,ll,ll,ll)> dfs=[&](ll i,ll p,ll d,ll lev){
        ll s=0;
        for(auto x:g[i])if(x.fi!=p&&!dead[x.fi]){
            range[x.se][lev].fi=cnt[lev];
            dfs(x.fi,i,d+cost[x.se],lev);s++;
            range[x.se][lev].se=cnt[lev];
        }
        if(s==0){
            cnt[lev]++;
            v[lev].pb(d);
        }
    };
    vvi gr(20,vi(n-1));
    function<ll(ll,ll,ll,ll,ll)> dfs2=[&](ll i,ll p,ll d,ll e,ll lev){
        gr[lev][e]=e;
        ll res=d;
        for(auto x:g[i])if(x.fi!=p&&!dead[x.fi]){
            chmax(res,dfs2(x.fi,i,d+cost[x.se],e,lev));
            gr[lev][x.se]=e;
        }
        return res;
    };
    auto onebig=[&](multiset<ll>&m){
        if(m.size()){
            auto itr=m.end();itr--;
            return *itr;
        }
        return 0ll;
    };
    auto twobig=[&](multiset<ll>&m){
        ll res=0;
        auto itr=m.end();
        rep(i,2){
            if(itr==m.begin())break;
            itr--;
            res+=*itr;
        }
        return res;
    };
    vi cur(n);
    function<void(ll,ll,ll)> CD=[&](ll root,ll lev,ll bef){
        dfs_sz(root,-1);
        ll cen=find_centroid(root,-1,root);
        par[cen]=bef;
        level[cen]=lev;
        dfs(cen,-1,0,lev);
        for(auto x:g[cen])if(!dead[x.fi])S[cen].insert(dfs2(x.fi,cen,cost[x.se],x.se,lev));
        cur[cen]=twobig(S[cen]);
        al.insert(cur[cen]);
        dead[cen]=true;
        for(auto x:g[cen])if(!dead[x.fi])CD(x.fi,lev+1,cen);
    };
    CD(0,0,-1);
    vector<segtree> seg;
    rep(i,20)seg.pb(segtree(v[i]));
    ll ans=0;
    auto update=[&](multiset<ll>&m,ll a,ll b){
        auto itr=m.lower_bound(a);
        assert(itr!=m.end()&&(*itr)==a);
        m.erase(itr);
        m.insert(b);
    };
    // outv(level);outv(par);
    // outv(cur);show(S[1]);
    rep(qq,q){
        ll i=readll(),nc=readll();
        i=(i+ans)%(n-1);
        nc=(nc+ans)%w;
        ll dc=nc-cost[i];
        // out(dc);
        cost[i]=nc;
        ans=0;
        ll x=edge[i].fi;
        if(level[edge[i].fi]>level[edge[i].se])x=edge[i].se;
        while(x!=-1){
            // out(x);
            ll e=gr[level[x]][i];
            // out(e);
            ll curr=seg[level[x]].get(range[e][level[x]].fi,range[e][level[x]].se);
            seg[level[x]].add(dc,range[i][level[x]].fi,range[i][level[x]].se);
            update(S[x],curr,seg[level[x]].get(range[e][level[x]].fi,range[e][level[x]].se));
            ll nex=twobig(S[x]);
            // out(nex);
            update(al,cur[x],nex);
            cur[x]=nex;
            x=par[x];
        }
        ans=onebig(al);
        out(ans);
    }
}