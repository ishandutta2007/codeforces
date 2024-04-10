#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
lli nCr[251][251];
lli mod=1e9+7;
lli C(int a, int b){
	if(b==0)return 1;
	if(a==b)return 1;
	if(nCr[a][b])return nCr[a][b];
	return nCr[a][b]=(C(a-1,b)+C(a-1,b-1))%mod;
}
lli n,k;
lli memo[2][251];
lli fastpow(lli a, lli b){
	lli old=a;
	if(memo[a-k+1][b])return memo[a-k+1][b];
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=ans*a%mod;
		}
		a=a*a%mod;
	}
	return memo[old-k+1][b]=ans;
}
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
lli dp[251][251];//first i rows, j columns filled.
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	sc(n,k);
	dp[0][0]=1;
	rep(i,1,n+1){
		rep(j,1,n+1){
			rep(l,(i==1?0:1),j){
				dp[i][j]=(dp[i][j]+(dp[i-1][l]*fastpow(k,l)%mod*C(n-l,n-j)%mod*fastpow(k-1,n-j)%mod))%mod;
			}
			dp[i][j]=(dp[i][j]+(dp[i-1][j]*make(fastpow(k,j)-fastpow(k-1,j))%mod*fastpow(k-1,n-j)%mod))%mod;
		}
	}
	prl(dp[n][n]);
    return 0;
}