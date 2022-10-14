#include<bits/stdc++.h>
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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=2e3+1;
lli mod=998244353;
lli dp[MAXN][2*MAXN+3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    lli k;
    sc(n,k);
    int ans[n];
    rep(i,0,n)sc(ans[i]);
    dp[0][n+1]=1;
    int toloop=2*n+3;
    rep(i,1,n+1){
    	rep(j,0,toloop){
		    if(ans[i-1]!=ans[i%n]){
			    dp[i][j]=((k-2)*dp[i-1][j])%mod;
    			dp[i][j]=(dp[i][j]+dp[i-1][j-1]+dp[i-1][j+1])%mod;
    		}
		    else{
			    dp[i][j]=(k*dp[i-1][j])%mod;
		    }
    	}
    }
    lli fin=0;
    rep(i,n+2,toloop){
		fin=(fin+dp[n][i])%mod;
    }
    prl(fin);
    return 0;
}