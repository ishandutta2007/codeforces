#include<bits/stdc++.h>
using namespace std;
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define F first
#define S second	
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define LCM(a,b) (a*b)/__gcd(a,b)
#define mii map<int,int>
#define mll map<ll,ll>
#define ub upper_bound
#define lb lower_bound
#define sz(x) (ll)x.size()
#define ld long double
#define pcnt(x) __builtin_popcountll(x)
const long long I1=1e9;
const long long I2=1e18;
const int32_t M1=1e9+7;
const int32_t M2=998244353;
template<typename T,typename T1>T maxn(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T minn(T &a,T1 b){if(b<a)a=b;return a;}

void solve()
{
  //code begins from here//
  int n;
  cin>>n;
  ll x1,y1,u1,v1;
 
  pll a[n];
  map <ld,ll> m[2];
  ll c1=0,c2=0;
  lop(i,n) {
     cin>>x1>>y1>>u1>>v1;
     if(u1==x1){
         if(y1>v1) c1++;
         else c2++;
     }
     else{
         if(v1==y1){
             if(x1>u1) m[0][0]++;
             else m[1][0]++;
         }
         else{
         ld cur = (v1-y1)/((u1-x1)*1.0);
         if(v1-y1>0) m[0][cur]++;
         else m[1][cur]++;
         }

     }
  }
     ll ans=0;
     for (auto u:m[0]){
         ans+=u.S*m[1][u.F];
     }
     ans+=c1*c2;
     cout<<ans<<endl;



}

signed main()
{
    IOS;
    #ifdef MODULO
        initialize();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    int testcase=1;
    cin>>testcase;
    while(testcase--) solve();
    return 0;
}