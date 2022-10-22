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

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,m,q;cin>>n>>m>>q;
    vvi t1(n,vi(2));
    vvi t2(m,vi(2));
    map<P,ll> mp;
    vi cnt1(3),cnt2(3),cnt3(2);cnt1[0]=n;cnt2[0]=m;
    rep(qq,q){
        ll a,b,c;cin>>a>>b>>c;a--;b--;
        if(!mp.count(P(a,b)))mp[P(a,b)]=-1;
        if(mp[P(a,b)]!=-1){
            ll k=mp[P(a,b)];
            t1[a][(b+k)&1]--;
            if(t1[a][(b+k)&1]==0){
                ll tmp=0;
                if(t1[a][1-((b+k)&1)])tmp=1;
                cnt1[tmp+1]--;cnt1[tmp]++;
            }
            t2[b][(a+k)&1]--;
            if(t2[b][(a+k)&1]==0){
                ll tmp=0;
                if(t2[b][1-((a+k)&1)])tmp=1;
                cnt2[tmp+1]--;cnt2[tmp]++;
            }
            cnt3[(a+b+k)&1]--;
        }
        mp[P(a,b)]=c;
        if(mp[P(a,b)]!=-1){
            ll k=mp[P(a,b)];
            t1[a][(b+k)&1]++;
            if(t1[a][(b+k)&1]==1){
                ll tmp=0;
                if(t1[a][1-((b+k)&1)])tmp=1;
                cnt1[tmp+1]++;cnt1[tmp]--;
            }
            t2[b][(a+k)&1]++;
            if(t2[b][(a+k)&1]==1){
                ll tmp=0;
                if(t2[b][1-((a+k)&1)])tmp=1;
                cnt2[tmp+1]++;cnt2[tmp]--;
            }
            cnt3[(a+b+k)&1]++;
        }
        ll ans=0;
        if(cnt1[2]==0)ans+=modpow(2,cnt1[0]);
        if(cnt2[2]==0)ans+=modpow(2,cnt2[0]);
        if(cnt3[0]==0)ans--;
        if(cnt3[1]==0)ans--;
        out(ans%mod);
    }
}