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
class bipartite_UF{
public:
    vi data;vi dif;stack<P> st;
    ll num(ll i){
        if(data[i]>0)return 0;
        return num(-data[i])+dif[i];
    }
    bipartite_UF(ll n):data(n,1),dif(n){}
    bool heigou(ll X,ll Y,bool undo=false){
        ll x=root(X),y=root(Y);
        if(data[x]>data[y]){swap(x,y);swap(X,Y);}
        if(undo){st.emplace(y,data[y]);st.emplace(x,data[x]);st.emplace(x,dif[x]);}
        if(x==y){
            if(num(X)%2==num(Y)%2)return false;
            return true;
        }
        if((num(X)+num(Y))%2==0)dif[x]=1;
        data[y]+=data[x];data[x]=-y;
        return true;
    }
    ll root(ll i){if(data[i]>0)return i;return root(-data[i]);}
    ll getsize(ll i){return data[root(i)];}
    bool same(ll a,ll b){return root(a)==root(b);}
    void undo(){dif[st.top().fi]=st.top().se;st.pop();rep(i,2){data[st.top().fi]=st.top().se;st.pop();}}
};
class dynamic_connectivity{
    ll N=1;
    vvp seg;
    bipartite_UF uf;
    vb ans;
    void add(int a,int b,int k,int l,int r,P p){
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b)seg[k].pb(p);
        else{
            add(a,b,k*2+1,l,(l+r)/2,p);add(a,b,k*2+2,(l+r)/2,r,p);
        }
    }
    void dfs(int i){
        rep(j,seg[i].size())if(!uf.heigou(seg[i][j].fi,seg[i][j].se,true)){
            rep(t,j+1)uf.undo();return;
        }
        if(i>=N-1){
            if(i-N+1<ans.size())ans[i-N+1]=true;
        }
        else{
            dfs(i*2+1);dfs(i*2+2);
        }
        rep(t,seg[i].size())uf.undo();
    }
public:
    dynamic_connectivity(int n,int t_max,vector<pair<P,P>> edge):uf(n),ans(t_max,false){
        while(N<t_max)N*=2;
        seg=vvp(N*2-1);
        for(auto x:edge)add(x.se.fi,x.se.se,0,0,N,x.fi);
        dfs(0);
    }
    vb solve(){return ans;}
};
int main(){
    ll n,m;cin>>n>>m;
    map<P,vi> mp;
    vector<pair<P,P>> edge;
    rep(i,m){
        ll a,b;cin>>a>>b;a--;b--;
        mp[P(a,b)].pb(i);
    }
    auto itr=mp.begin();
    while(itr!=mp.end()){
        vi x=itr->se;
        for(int i=0;i<x.size();i+=2){
            ll t=m;
            if(i+1<x.size())t=x[i+1];
            edge.pb(itr->fi,P(x[i],t));
        }
        itr++;
    }
    dynamic_connectivity d(n,m,edge);
    vb x=d.solve();
    for(auto k:x)YESNO(k);
}