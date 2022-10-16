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
const int MAXN=2e5+10,mod=998244353;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
ll I(ll a){return mypow(a,mod-2);}
ll fact[MAXN],inv[MAXN];
int n,m,s[MAXN],t[MAXN];
ll suf=1;
ll b[MAXN],ans;
struct BIT{
    ll t[MAXN];
    void upd(int x,ll val){
        for(;x<=2e5;x+=lowbit(x))t[x]=(t[x]+val+mod)%mod;
    }
    ll qry(int x){
        ll ret=0;
        for(;x;x-=lowbit(x))ret=(ret+t[x])%mod;
        return ret;
    }
}bit;
int main(){
    fact[0]=1;rep(i,1,2e5)fact[i]=fact[i-1]*i%mod;
    rep(i,0,2e5)inv[i]=mypow(fact[i],mod-2);
    cin>>n>>m;
    rep(i,1,n)cin>>s[i];
    rep(i,1,m)cin>>t[i];
    rep(i,1,n)b[s[i]]++;
    rep(i,1,2e5){
        if(b[i])bit.upd(i,fact[b[i]]*inv[b[i]-1]%mod);
        suf=suf*inv[b[i]]%mod;
    }
    rep(i,1,m){
        int c=t[i];
        ll val=fact[n-i]*suf%mod;
        ll sum=0;
        if(t[i]!=1)sum=bit.qry(t[i]-1);
        ans=(ans+sum*val%mod)%mod;
        if(b[c]==0)break;
        bit.upd(c,mod-fact[b[c]]*inv[b[c]-1]%mod);
        suf=suf*fact[b[c]]%mod;
        b[c]--;
        suf=suf*inv[b[c]]%mod;
        if(b[c])bit.upd(c,fact[b[c]]*inv[b[c]-1]%mod);
        if(n<m&&i==n){
            ans=(ans+1)%mod;
            break;
        }
    }
    cout<<ans;
    return 0;
}