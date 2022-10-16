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
ll T,n;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
ll myinv(ll a){
    return mypow(a,mod-2);
}
ll F[MAXN],sum[MAXN];
void calc(){
    rep(i,1,n)F[i]=0,sum[i]=0;
    F[n]=1;sum[n]=1;
    sum[n+1]=0;
    per(i,n-1,1){
        F[i]=0;
        ll L=i+1,R=2*i-1;
        R=min(R,n);
        if(L>R){
            F[i]=0;
        }else{
            F[i]=(sum[L]-sum[R+1]+mod)%mod;
        }
        sum[i]=(sum[i+1]+F[i])%mod;
    }
}
void solve(){
    cin>>n;
    if(n==1){
        cout<<"1\n";
        return;
    }
    calc();
    rep(i,1,n){
        ll maxj=i/2;
        ll res=myinv(mypow(2,n))*mypow(2,maxj)%mod*F[i]%mod;
        
        if(i==n){
            rep(j,1,n){
                if(n-j <= j){
                    res=(res+myinv(mypow(2,n))*mypow(2,max(0LL,n-j-1))%mod)%mod;
                }
            }
        }else res=res*2%mod;
        
        cout<<res<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}