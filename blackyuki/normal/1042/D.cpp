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
map<ll,ll> st;
vvi wm(62);
ll N;
void init(vi v){
    N=v.size();
    for(ll i=61;i>=0;i--){
        vvi nv(2);
        wm[i].pb(0);
        rep(j,N){
            wm[i].pb((v[j]>>i&1ll)+wm[i].back());
            nv[v[j]>>i&1ll].pb(v[j]);
        }
        v=nv[0];v.insert(v.end(),all(nv[1]));
    }
    rep(i,N)if(!st.count(v[i]))st[v[i]]=i;
}
ll rank(ll c,ll idx){
    if(!st.count(c))return 0;
    for(ll i=61;i>=0;i--){
        if(c>>i&1ll)idx=wm[i][idx]+(N-wm[i][N]);
        else idx-=wm[i][idx];
    }
    return max(0ll,idx-st[c]);
}
ll kthmin(ll l,ll r,ll k){
    ll res=0;
    for(ll i=61;i>=0;i--){
        ll cnt=(r-l)-(wm[i][r]-wm[i][l]);
        if(cnt<=k){
            k-=cnt;
            l=N-wm[i][N]+wm[i][l];
            r=N-wm[i][N]+wm[i][r];
            res+=1ll<<i;
        }
        else{
            l-=wm[i][l];
            r-=wm[i][r];
        }
    }
    return res;
}
ll rangefreq(ll l,ll r,ll k){ //
    k++;
    ll res=0;
    for(ll i=61;i>=0;i--){
        ll cnt=(r-l)-(wm[i][r]-wm[i][l]);
        if(k>>i&1ll){
            res+=cnt;
            l=N-wm[i][N]+wm[i][l];
            r=N-wm[i][N]+wm[i][r];
        }
        else{
            l-=wm[i][l];
            r-=wm[i][r];
        }
    }
    return res;
}

int main(){
    ll n,k;cin>>n>>k;
    vi v(n+1);
    rep(i,n){
        cin>>v[i+1];
        v[i+1]+=v[i];
    }
    n++;
    rep(i,n)v[i]+=inf/100;
    init(v);
    ll ans=0;
    rep(i,n-1){
        ans+=rangefreq(i+1,n,v[i]+k-1);
    }
    out(ans);
}