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
const ll mod=998244353;
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
    vi data;stack<P> st;
public:
    UF(ll n){
        data=vi(n,1);
    }
    bool merge(ll x,ll y,bool undo=false){
        x=root(x);y=root(y);
        if(data[x]>data[y])swap(x,y);
        if(undo){st.emplace(y,data[y]);st.emplace(x,data[x]);}
        if(x==y)return false;
        data[y]+=data[x];data[x]=-y;
        return true;
    }
    ll root(ll i){if(data[i]>0)return i;return root(-data[i]);}
    ll getsize(ll i){return data[root(i)];}
    bool same(ll a,ll b){return root(a)==root(b);}
    void undo(){rep(i,2){data[st.top().fi]=st.top().se;st.pop();}}
};

int main(){
    ll n,m;cin>>n>>m;
    ll mi=0;
    set<P> edge;
    vector<PP> edges;
    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;a--;b--;if(a>b)swap(a,b);
        edge.insert(P(a,b));
        edges.pb(c,a,b);
        mi^=c;
    }
    sort(all(edges));
    set<ll> S;
    rep(i,n)S.insert(i);
    vi gr(n);
    ll cnt_gr=0;
    while(S.size()){
        ll i=*S.begin();S.erase(i);
        queue<ll> que;que.push(i);
        while(!que.empty()){
            ll t=que.front();que.pop();
            gr[t]=cnt_gr;
            auto itr=S.begin();
            while(itr!=S.end()){
                if(edge.find(P(min(t,*itr),max(t,*itr)))==edge.end()){
                    que.push(*itr);
                    S.erase(itr++);
                }
                else itr++;
            }
        }
        cnt_gr++;
    }
    UF uf(cnt_gr),uf2(n);
    ll ans=0;
    for(auto x:edges){
        ll w,a,b;tie(w,a,b)=x;
        if(uf.merge(gr[a],gr[b])){
            uf2.merge(a,b);ans+=w;
        }
        else if(uf2.merge(a,b))chmin(mi,w);
    }
    if(m+(n-cnt_gr)==n*(n-1)/2)ans+=mi;
    out(ans);
}