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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    sc(q);
    while(q--){
    	int n;
    	sc(n);
		lli dp[n][3];
		lli prevheight;
		dp[0][0]=0;
		sc(prevheight,dp[0][1]);
		dp[0][2]=dp[0][1]*2;
	    lli a,b;
		rep(i,1,n){
			sc(a,b);
			rep(j,0,3)dp[i][j]=LLONG_MAX;
			rep(j,(lli)0,(lli)3)rep(k,(lli)0,(lli)3){
				if(a+j!=prevheight+k){
					dp[i][j]=min(dp[i][j],dp[i-1][k]+b*j);
				}
			}
			prevheight=a;
		}
		prl(min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])));
    }
    return 0;
}