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
class segtree{
    vi seg;ll n;
public:
    ll g=-1;
    ll f(ll a,ll b){
        return max(a,b);
    }
    bool comp(ll x,ll cur){
        return x>=cur;
    }
    segtree(ll n_,ll k):n(n_){
        seg=vi(n*2,g);
        rep(i,n)seg[i+n]=k;
        for(ll i=n-1;i;i--)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    segtree(vi v):n(v.size()){
        seg=vi(n*2,g);
        rep(i,n)seg[i+n]=v[i];
        for(ll i=n-1;i;i--)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    void add(ll i,ll x){
        i+=n;seg[i]+=x;
        for(i>>=1;i;i>>=1)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    void update(ll i,ll x){
        i+=n;seg[i]=x;
        for(i>>=1;i;i>>=1)seg[i]=f(seg[i*2],seg[i*2+1]);
    }
    ll get(ll l,ll r){
        ll resl=g,resr=g;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)resl=f(resl,seg[l++]);
            if(r&1)resr=f(seg[--r],resr);
        }
        return f(resl,resr);
    }
    ll solve(ll l,ll x){ //comp(x,f([l,r])) == true r
        ll cur=g;
        for(l+=n;l;l>>=1)if(l&1){
            if(comp(x,f(cur,seg[l])))break;
            cur=f(cur,seg[l++]);
        }
        if(l==0)return n;
        while(l<n){
            l<<=1;
            if(!comp(x,f(cur,seg[l])))cur=f(cur,seg[l++]);
        }
        return l-n;
    }
    void debug(ll n){
        rep(i,n)cout<<' '<<seg[i+n];cout<<endl;
    }
};
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,q;cin>>n>>q;
    vvp g(n);
    rep(i,n-1){
        ll a,b,c;cin>>a>>b>>c;a--;b--;
        g[a].pb(b,c);g[b].pb(a,c);
    }
    vi dep(n);
    vvp table(20,vp(n,P(-1,-1)));
    function<void(ll,ll,ll,ll)> dfs=[&](ll i,ll p,ll d,ll e){
        table[0][i]=P(p,e);dep[i]=d;
        for(auto x:g[i])if(x.fi!=p)dfs(x.fi,i,d+1,x.se);
    };dfs(0,-1,0,0);
    rep(i,19)rep(j,n)if(table[i][j].fi!=-1){
        table[i+1][j].fi=table[i][table[i][j].fi].fi;
        table[i+1][j].se=max(table[i][j].se,table[i][table[i][j].fi].se);
    }
    auto lca=[&](ll a,ll b){
        ll res=-1;
        if(dep[a]>dep[b])swap(a,b);
        ll dif=dep[b]-dep[a];
        rep(i,20)if(dif>>i&1){
            chmax(res,table[i][b].se);
            b=table[i][b].fi;
        }
        if(a==b)return res;
        for(ll i=19;i>=0;i--)if(table[i][a].fi!=table[i][b].fi){
            chmax(res,table[i][a].se);
            chmax(res,table[i][b].se);
            a=table[i][a].fi;b=table[i][b].fi;
        }
        chmax(res,table[0][a].se);
        chmax(res,table[0][b].se);
        return res;
    };
    vi tmp(n,-1);
    set<P> S;
    multiset<ll> T;
    vi segi(n-1);
    rep(i,n-1)segi[i]=lca(i,i+1);
    segtree seg(segi);
    auto AD=[&](P p){
        auto itr=S.lower_bound(P(p.se+1,-1));
        if(itr!=S.end()){
            tmp[p.fi]=lca(p.fi,itr->fi);
            T.insert(tmp[p.fi]);
        }
        if(itr!=S.begin()){
            itr--;
            if(tmp[itr->fi]!=-1)T.erase(T.lower_bound(tmp[itr->fi]));
            tmp[itr->fi]=lca(itr->fi,p.fi);
            T.insert(tmp[itr->fi]);
        }
        T.insert(seg.get(p.fi,p.se));
    };
    auto ER=[&](P p){
        auto itr=S.lower_bound(P(p.se+1,-1));
        ll nex=-1;
        if(itr!=S.end()){
            T.erase(T.lower_bound(tmp[p.fi]));
            tmp[p.fi]=-1;
            nex=itr->fi;
        }
        itr--;
        if(itr!=S.begin()){
            itr--;
            T.erase(T.lower_bound(tmp[itr->fi]));
            tmp[itr->fi]=-1;
            if(nex!=-1){
                tmp[itr->fi]=lca(itr->fi,nex);
                T.insert(tmp[itr->fi]);
            }
        }
        T.erase(T.lower_bound(seg.get(p.fi,p.se)));
    };
    auto ad=[&](ll l,ll r){
        auto itr=S.lower_bound(P(r+1,-1));
        while(itr!=S.begin()){
            itr--;
            if(itr->se<l)break;
            chmin(l,itr->fi);chmax(r,itr->se);
            ER(*itr);
            S.erase(itr++);
        }
        AD(P(l,r));
        S.insert(P(l,r));
    };
    auto er=[&](ll l,ll r){
        auto itr=S.lower_bound(P(r+1,-1));
        ll nl=inf,nr=-inf;
        while(itr!=S.begin()){
            itr--;
            if(itr->se<l)break;
            chmin(nl,itr->fi);chmax(nr,itr->se);
            ER(*itr);
            S.erase(itr++);
        }
        if(nl<=l-1){
            AD(P(nl,l-1));
            S.insert(P(nl,l-1));
        }
        if(r+1<=nr){
            AD(P(r+1,nr));
            S.insert(P(r+1,nr));
        }
    };
    rep(qq,q){
        ll t;cin>>t;
        if(t==1){
            ll l,r;cin>>l>>r;l--;r--;
            ad(l,r);
        }
        if(t==2){
            ll l,r;cin>>l>>r;l--;r--;
            er(l,r);
        }
        if(t==3){
            ll x;cin>>x;x--;
            bool flag=true;
            auto itr=S.lower_bound(P(x+1,-1));
            if(itr!=S.begin()){
                itr--;
                if(itr->se>=x)flag=false;
            }
            ad(x,x);
            if(T.size()==0)out(-1);
            else{
                // outset(T);
                auto itr=T.end();itr--;
                out(*itr);
                // vp r;
                // for(auto x:S)r.pb(x);
                // outvp(r);
            }
            if(flag)er(x,x);
        }
    }
}