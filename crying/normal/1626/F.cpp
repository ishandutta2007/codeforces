#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e7+10,MAXM=1e6,mod=998244353;
ll n,a[MAXN],x,y,k,M,m;
ll ans,power[20],dp[2][MAXM];
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
int main(){
    cin>>n>>a[1]>>x>>y>>k>>M;
    power[0]=1;rep(i,1,k)power[i]=power[i-1]*n%mod;
    rep(i,2,n)a[i]=(a[i-1]*x+y)%M;
    m=1;
    rep(i,2,k-1)m=m/gcd(m,i)*i;
    rep(i,1,n)ans=(ans+((a[i]/m)*m)*k%mod*power[k-1])%mod,a[i]%=m,dp[0][a[i]]++;
    rep(i,0,k-1){
        rep(j,0,m-1)ans=(ans+j*dp[i&1][j]%mod*power[k-i-1])%mod;
        rep(j,0,m-1){
            ll& ret=dp[(i+1)&1][j-j%(i+1)];
            ret=(ret+dp[i&1][j])%mod;
            ll& ret2=dp[(i+1)&1][j];
            ret2=(ret2+dp[i&1][j]*(n-1))%mod;
        }
        memset(dp[i&1],0,sizeof dp[i&1]);
    }
    cout<<ans;
    return 0;
}