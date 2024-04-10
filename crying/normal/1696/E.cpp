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
const int MAXN=5e5+10,mod=1e9+7,LIM=5e5;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;
    return tmp;
}
ll n,a[MAXN],ans;
ll fact[MAXN],inv[MAXN];
ll C(ll n,ll m){
    if(n<m || n<0 || m<0)return 0;
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    fact[0]=1;rep(i,1,LIM)fact[i]=fact[i-1]*i%mod;
    rep(i,0,LIM)inv[i]=mypow(fact[i],mod-2);
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        ans=(ans+C(i+a[i],i+1))%mod;
    }
    cout<<ans;
    return 0;
}