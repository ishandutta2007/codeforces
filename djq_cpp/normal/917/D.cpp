//our goal is to calculate sigma(PI(vi^(si+1)))
//it equals to sigma(PI(vi)*PI(vi^si))
//which equals to sigma(PI(vi))*sigma(vi)^sigma(si)
//or sigma(PI(vi))*N^(C-2)
//a[n-i]=sigma(PI(v[1...i], where sigma(v[1...i])=n))*n^(i-2)
//b[i]=a[i]-a[i+1]+a[i+2]-a[i+3]+... or sigma(a[i+k]*(-1)^k)
//res[i]=res[i]-res[i+1]
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
ll power(ll bs,int T){
	if(T==0)return 1LL;
	ll med=power(bs,T>>1);
	med=med*med%INF;
	if(T&1)med=med*bs%INF;
	return med;
}
vector<int> G[105];
int sz[105];
ll dp[105][105][105],fw[105][105];
bool fre[105][105][105];
void update(int v,int c,int n,ll ns){
	ns%=INF;
	if(fre[v][c][n]){
		fre[v][c][n]=false;
		dp[v][c][n]=ns;
	}else{
		dp[v][c][n]=dp[v][c][n]+ns;
		if(dp[v][c][n]>=INF)dp[v][c][n]-=INF;
	}
}
void solve(int v,int par){
	dp[v][1][1]=1LL;
	fre[v][1][1]=true;
	int csz=1;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		solve(u,v);
		for(int c1=csz;c1>=1;c1--)for(int c2=sz[u];c2>=1;c2--){
			for(int n1=csz;n1>=1;n1--){
				update(v,c1+c2,n1,dp[v][c1][n1]*fw[u][c2]);
				for(int n2=sz[u];n2>=1;n2--)
				update(v,c1+c2-1,n1+n2,dp[v][c1][n1]*dp[u][c2][n2]);
			}
		}
		csz+=sz[u];
		for(int c=csz;c>=1;c--)for(int n=csz;n>=1;n--)
		if(fre[v][c][n])dp[v][c][n]=0LL;
		else fre[v][c][n]=true;
	}
	sz[v]=csz;
	for(int c=csz;c>=1;c--)for(int n=csz;n>=1;n--)
	fw[v][c]=(fw[v][c]+dp[v][c][n]*n)%INF;
}
ll C[105][105];
void getC(){
	C[0][0]=1;
	rep1(i,100){
		C[i][0]=1;
		rep1(j,100)C[i][j]=(C[i-1][j-1]+C[i-1][j])%INF;
	}
}
ll ca[105],ans[105];
int main(){
	getC();
	int n,u,v;
	scanf("%d",&n);
	rep(k,n-1){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve(1,-1);
	rep1(k,n)ca[n-k]=k==1?1:fw[1][k]*power(n,k-2)%INF;
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++)
		ca[i]-=C[j][i]*ca[j]%INF;
	}
	rep(k,n)printf("%I64d ",(ca[k]+(ll(INF)<<30))%INF);
	return 0;
}