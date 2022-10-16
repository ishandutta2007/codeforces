#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e5+10,LIM=1e5,mod=1e9+7;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
ll myinv(ll a){
    return mypow(a,mod-2);
}
ll fact[MAXN],inv[MAXN];
ll C(ll n,ll m){
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
ll n,k,ans;
int main(){
    fact[0]=1;rep(i,1,LIM)fact[i]=fact[i-1]*i%mod;
    inv[LIM]=myinv(fact[LIM]);per(i,LIM-1,0)inv[i]=inv[i+1]*(i+1)%mod;
    cin>>n>>k;
    k=min(n,k);
    rep(i,0,k)ans=(ans+C(n,i))%mod;
    cout<<ans<<"\n";

    return 0;
}