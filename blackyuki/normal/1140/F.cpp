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

class UF{
    vp data;stack<pair<ll,P>> st;
public:
    ll val=0;
    UF(ll n){
        data=vp(n*2);
        rep(i,n)data[i]=P(1,0);
        rep(i,n)data[i+n]=P(0,1);
    }
    void merge(ll x,ll y){
        x=root(x);y=root(y);
        if(data[x].fi+data[x].se>data[y].fi+data[y].se)swap(x,y);
        st.emplace(y,data[y]);st.emplace(x,data[x]);st.emplace(-1,P(val,-1));
        if(x==y)return;
        val-=data[x].fi*data[x].se+data[y].fi*data[y].se;
        data[y].fi+=data[x].fi;data[y].se+=data[x].se;data[x]=P(-y,-1);
        val+=data[y].fi*data[y].se;
    }
    ll root(ll i){while(data[i].se==-1)i=-data[i].fi;return i;}
    void undo(){
        val=st.top().se.fi;st.pop();
        rep(i,2){data[st.top().fi]=st.top().se;st.pop();}
    }
};

class dyconne{
    vvp seg;ll n;
    UF uf;
public:
    vi res;
    dyconne(ll n_,ll m):n(n_),uf(m){
        seg=vvp(n*2);res=vi(n);
    }
    void add(ll l,ll r,P x){
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)seg[l++].pb(x);
            if(r&1)seg[--r].pb(x);
        }
    }
    void dfs(ll i){
        for(auto x:seg[i])uf.merge(x.fi,x.se);
        if(i>=n)res[i-n]=uf.val;
        else{
            dfs(i*2);dfs(i*2+1);
        }
        for(auto x:seg[i])uf.undo();
    }
};

int main(){
    // cin.tie(0);ios::sync_with_stdio(false);
    ll mx=300005;
    ll q;cin>>q;
    map<P,vi> mp;
    rep(i,q){
        ll x,y;cin>>x>>y;
        mp[P(x,y+mx)].pb(i);
    }
    dyconne seg(q,mx);
    auto itr=mp.begin();
    while(itr!=mp.end()){
        vi tmp=itr->se;
        if(tmp.size()%2)tmp.pb(q);
        rep(i,tmp.size()/2)seg.add(tmp[i*2],tmp[i*2+1],itr->fi);
        itr++;
    }
    seg.dfs(1);
    outv(seg.res);
}