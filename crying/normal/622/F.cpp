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
const int MAXN=1e6+10,mod=1e9+7;
ll mypow(ll a,ll n){if(!n)return 1;ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;if(n&1)tmp=tmp*a%mod;return tmp;}
ll inv(ll a){return mypow(a%mod,mod-2);}
ll n,k;
ll y[MAXN];
ll fact[MAXN],factinv[MAXN];
ll P(int x){return (x&1)?(mod-1):1;}
ll F(ll n){
    if(n<=k+2)return y[n];
    ll ret=1,lval=1,sum=0;
    rep(i,1,k+2)lval=lval*(n-i+mod)%mod;
    rep(i,1,k+2){
        ll w=y[i]*factinv[i-1]%mod*factinv[k+2-i]%mod*P(k+2-i)%mod;
        sum=(sum+w*inv(n-i+mod)%mod)%mod;
    }
    ret=lval*sum%mod;
    return ret;
}
int main(){
    cin>>n>>k;
    rep(i,1,k+2)y[i]=(y[i-1]+mypow(i,k))%mod;
    fact[0]=1;rep(i,1,k+2)fact[i]=fact[i-1]*i%mod;
    factinv[k+2]=inv(fact[k+2]);per(i,k+1,0)factinv[i]=factinv[i+1]*(i+1)%mod;
    cout<<F(n);
    return 0;
}