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
ll max_n=2500005;
void solve(ll n,vi v){
    vp seen(max_n*2,P(-1,-1));
    vvi cnt(max_n);
    rep(i,n)cnt[v[i]].pb(i);
    vi m;
    rep(i,max_n)if(cnt[i].size()>=2){
        m.pb(i);
    }
    if(m.size()>=2){
        out("YES");
        cout<<cnt[m[0]][0]+1<<' '<<cnt[m[1]][0]+1<<' '<<cnt[m[0]][1]+1<<' '<<cnt[m[1]][1]+1<<endl;
        return;
    }
    if(m.size()==1&&cnt[m[0]].size()>=4){
        out("YES");
        cout<<cnt[m[0]][0]+1<<' '<<cnt[m[0]][1]+1<<' '<<cnt[m[0]][2]+1<<' '<<cnt[m[0]][3]+1<<endl;
        return;
    }
    vb ok(n,true);
    if(m.size()==1){
        ll i=m[0];
        REP(j,1,cnt[i].size())ok[cnt[i][j]]=false;
        seen[i*2]=P(cnt[i][0],cnt[i][1]);
    }
    rep(i,n)rep(j,i)if(ok[i]&&ok[j]){
        ll x=v[i]+v[j];
        if(seen[x]!=P(-1,-1)){
            out("YES");
            cout<<i+1<<' '<<j+1<<' '<<seen[x].fi+1<<' '<<seen[x].se+1<<endl;
            return;
        }
        seen[x]=P(i,j);
    }
    out("NO");
}
int main(){
    ll n;cin>>n;
    vi v(n);rep(i,n)cin>>v[i];
    solve(n,v);
}