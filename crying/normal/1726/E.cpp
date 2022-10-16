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
const int MAXN=6e5+10,LIM=6e5,mod=998244353;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
ll myinv(ll a){return mypow(a,mod-2);}
void add(ll& x,ll y){
    x=(x+y)%mod;
}
ll fact[MAXN],inv[MAXN];
ll F[MAXN],G[MAXN];
ll C(ll n,ll m){
    if(!m)return 1;
    if(n<m || n<0 || m<0)return 0;
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
ll T,n,ans;
void solve(){
    cin>>n;
    ans=0;
    rep(i,0,n/2){
        if(odd(i))continue;
        ll ways=C(n-i,i);
        add(ans,ways*G[i]%mod*F[n-2*i]%mod);
    }
    cout<<ans<<"\n";
}
int main(){
    fact[0]=1;rep(i,1,LIM)fact[i]=fact[i-1]*i%mod;
    inv[LIM]=myinv(fact[LIM]);per(i,LIM-1,0)inv[i]=(inv[i+1])*(i+1)%mod;
    F[0]=F[1]=1;rep(i,2,LIM)F[i]=(F[i-1]+(i-1)*(F[i-2])%mod)%mod;
    G[0]=1;rep(i,1,LIM)if(even(i))G[i]=2*(i-1)%mod*G[i-2]%mod;
    cin>>T;
    while(T--)solve();

    return 0;
}