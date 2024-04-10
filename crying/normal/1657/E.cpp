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
const int MAXN=310,mod=998244353;
ll n,k,c[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;return tmp;
}
int main(){
    c[0][0]=1;
    rep(i,1,300){
        c[i][0]=1;
        rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    cin>>n>>k;
    dp[0][0]=1;
    rep(i,1,k){
        rep(j,0,n-1){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            rep(cnt,1,n-1-j){
                dp[i][j+cnt]=(dp[i][j+cnt]+dp[i-1][j]*c[n-1-j][cnt]%mod*mypow(k-i+1,cnt*j+cnt*(cnt-1)/2)%mod)%mod;
            }
        }
    }
    cout<<dp[k][n-1]<<endl;
    return 0;
}