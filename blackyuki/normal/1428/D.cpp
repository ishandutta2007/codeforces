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

int main(){
    ll n;cin>>n;
    vp v;
    vp ans;
    ll cnt=0;
    rep(i,n){
        ll a;cin>>a;
        if(a)v.pb(i,a);
        if(a==3){
            if(cnt)ans.pb(cnt,i+1);
            cnt++;
            ans.pb(cnt,i+1);
        }
    }
    if(v.size()==0)dame(0);
    if(v.back().se!=1)dame(-1);
    ll two=-1;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i].se==2&&two==-1)two=v[i].fi;
        if(v[i].se==3){
            if(two==-1){
                ans.pb(cnt,v.back().fi+1);
                cnt++;
                ans.pb(cnt,v.back().fi+1);
            }
            else{
                ans.pb(cnt,two+1);
                cnt++;
                ans.pb(cnt,two+1);
                ans.pb(cnt,v.back().fi+1);
            }
            v.pop_back();
            break;
        }
    }
    cnt++;
    vp a;
    vi st;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i].fi==two&&ans.size())continue;
        if(v[i].se==1)st.pb(i);
        else if(v[i].se==2){
            if(st.size()==0)dame(-1);
            a.pb(i,st.back());
            st.pop_back();
        }
    }
    for(ll x:st)ans.pb(cnt++,v[x].fi+1);
    for(auto x:a){
        ans.pb(cnt,v[x.fi].fi+1);
        ans.pb(cnt,v[x.se].fi+1);
        cnt++;
    }
    out(ans.size());
    for(auto x:ans)cout<<x.fi<<' '<<x.se<<endl;
}