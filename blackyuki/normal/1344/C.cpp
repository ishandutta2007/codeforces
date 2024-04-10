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
#define dupli(a) erase(unique(all(a)),a.end())
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=1000000007;
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
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}

vvi to,ot;
ll id=0;
vector<bool> used,used2;
vi memo,scc;
void dfs(ll i){
    used[i]=true;
    for(ll x:to[i])if(!used[x])dfs(x);
    memo[id]=i;
    id++;
}
void dfs2(ll i){
    used2[i]=true;
    for(ll x:ot[i])if(!used2[x])dfs2(x);
    scc[i]=id;
}
vb done1,done2;
void dfs3(int i){
    if(done1[i])return;
    done1[i]=true;
    for(ll x:ot[i])dfs3(x);
}
void dfs4(int i){
    if(done2[i])return;
    done2[i]=true;
    for(ll x:to[i])dfs4(x);
}
int main(){
    ll n,m;cin>>n>>m;
    scc=vi(n);
    to=vvi(n);
    ot=vvi(n);
    memo=vi(n);
    used=vector<bool>(n,false);
    used2=vector<bool>(n,false);
    rep(i,m){
        ll a,b;cin>>a>>b;
        to[a-1].pb(b-1);
        ot[b-1].pb(a-1);
    }
    rep(i,n)if(!used[i])dfs(i);
    id=0;
    for(ll i=n-1;i>=0;i--)if(!used2[memo[i]]){
        dfs2(memo[i]);
        id++;
    }
    if(id!=n)dame(-1);
    done1=vb(n,false);done2=vb(n,false);
    vector<char> ans(n,'E');
    ll cnt=0;
    rep(i,n){
        if(!(done1[i]||done2[i])){
            ans[i]='A';
            cnt++;
        }
        dfs3(i);dfs4(i);
    }
    out(cnt);
    for(char c:ans)cout<<c;
    cout<<endl;
}