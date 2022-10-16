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
const int MAXN=1e6+10,LIM=1e6,mod=1e9+7;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
ll fact[MAXN],inv[MAXN];
ll power[MAXN],invp[MAXN];
ll C(ll n,ll m){
    if(n<0 || m<0 || n<m)return 0;
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
ll T,m,n,k;
ll ans;
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    if(n==m){
        printf("%lld\n",n*k%mod);
        return;
    }
    ll ans=0;
    rep(i,1,n){
        ll ret=i*k%mod;
        ret=ret*C(n-i-1,m-i)%mod;
        ret=ret*invp[n-i]%mod;
        ans=(ans+ret)%mod;
    }
    printf("%lld\n",ans);
}
int main(){
    fact[0]=1;rep(i,1,LIM)fact[i]=fact[i-1]*i%mod;
    inv[LIM]=mypow(fact[LIM],mod-2);
    per(i,LIM-1,0)inv[i]=inv[i+1]*(i+1)%mod;
    power[0]=1;rep(i,1,LIM)power[i]=power[i-1]*2%mod;
    invp[LIM]=mypow(power[LIM],mod-2);
    per(i,LIM-1,0)invp[i]=invp[i+1]*2%mod;
    scanf("%lld",&T);
    while(T--)solve();

    return 0;
}