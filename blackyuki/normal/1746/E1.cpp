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
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}

int main(){
    ll n;cin>>n;
    vi v(n);
    rep(i,n)v[i]=i+1;
    while(v.size()>=4){
        vvi tmp(4);
        rep(i,v.size())tmp[i%4].pb(v[i]);
        int a=0,b=0;
        {
            vi ask;
            for(ll x:tmp[1])ask.pb(x);
            for(ll x:tmp[3])ask.pb(x);
            cout<<"? "<<ask.size()<<' ';
            outv(ask);fflush(stdout);
            string s;cin>>s;
            if(s=="YES")a=1;
        }
        {
            vi ask;
            for(ll x:tmp[2])ask.pb(x);
            for(ll x:tmp[3])ask.pb(x);
            cout<<"? "<<ask.size()<<' ';
            outv(ask);fflush(stdout);
            string s;cin>>s;
            if(s=="YES")b=1;
        }
        int t;
        if(a==0&&b==0)t=3;
        if(a==0&&b==1)t=1;
        if(a==1&&b==0)t=2;
        if(a==1&&b==1)t=0;
        v=vi(0);
        rep(j,4)if(t!=j)for(ll x:tmp[j])v.pb(x);
    }
    if(v.size()==3){
        {
            vi ask={v[0],v[1]};
            cout<<"? "<<ask.size()<<' ';
            outv(ask);fflush(stdout);
            string s;cin>>s;
            if(s=="NO"){
                vi ask={v[0]};
                cout<<"? "<<ask.size()<<' ';
                outv(ask);fflush(stdout);
                string s;cin>>s;
                if(s=="YES"){
                    v=vi{v[0],v[2]};
                }
                else{
                    v=vi{v[1],v[2]};
                }
            }
            else{
                vi ask={v[0],v[1]};
                cout<<"? "<<ask.size()<<' ';
                outv(ask);fflush(stdout);
                string s;cin>>s;
                if(s=="YES"){
                    v=vi{v[0],v[1]};
                }
                else{
                    vi ask={v[0]};
                    cout<<"? "<<ask.size()<<' ';
                    outv(ask);fflush(stdout);
                    string s;cin>>s;
                    if(s=="YES"){
                        v=vi{v[0],v[2]};
                    }
                    else{
                        v=vi{v[1],v[2]};
                    }
                }
            }
        }
    }
    rep(j,v.size()){
        cout<<"! "<<v[j]<<endl;
        fflush(stdout);
        string s;cin>>s;
        if(s==":)")return 0;
    }
}