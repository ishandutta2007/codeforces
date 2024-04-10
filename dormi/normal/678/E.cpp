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
double matrix[18][18];
double dp[(1<<18)][18];
int n;
double run(int mask, int tofight){
	if(dp[mask][tofight]!=-1)return dp[mask][tofight];
	if(__builtin_popcount(mask)==n-1)return dp[mask][tofight]=(tofight?0:1);
	double best=0;
	for(int i=0;i<n;i++){
		if(i!=tofight&&!(mask&(1<<i))){
			best=max(best,matrix[tofight][i]*run(mask+(1<<i),tofight)+matrix[i][tofight]*run(mask+(1<<tofight),i));
		}
	}
	return dp[mask][tofight]=best;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	sc(n);
	for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++)dp[i][j]=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)sc(matrix[i][j]);
	}
	double best=0;
	for(int i=0;i<n;i++)best=max(best,run(0,i));
	prl(best);
    return 0;
}