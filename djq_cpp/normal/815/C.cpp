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
vector<int> son[5005];
int n,c[5005],d[5005],dp[2][5005][5005];
int dfs(int v){
	int cnt=1;
	rep1(k,n)dp[0][v][k]=dp[1][v][k]=INF;
	dp[0][v][1]=c[v];
	dp[1][v][0]=c[v]-d[v];
	rep(k,son[v].size()){
		int u=son[v][k],cc=dfs(u);
		for(int i=cnt;i>=0;i--)for(int j=cc;j>=0;j--){
			dp[0][v][i+j]=min(dp[0][v][i+j],dp[0][v][i]+dp[0][u][j]);
			dp[1][v][i+j]=min(dp[1][v][i+j],dp[1][v][i]+dp[1][u][j]);
		}
		cnt+=cc;
	}
	for(int k=cnt-1;k>=0;k--)
	dp[1][v][k+1]=dp[1][v][k];
	dp[1][v][0]=0;
	for(int k=0;k<=cnt;k++)dp[1][v][k]=min(dp[1][v][k],dp[0][v][k]);
	return cnt;
}
int main(){
	int l,p,ans=0;
	scanf("%d%d",&n,&l);
	rep1(k,n){
		scanf("%d%d",&c[k],&d[k]);
		if(k>1){
			scanf("%d",&p);
			son[p].push_back(k);
		}
	}
	dfs(1);
	for(int k=0;k<=n;k++)if(dp[1][1][k]<=l)ans=k;
	printf("%d\n",ans);
	return 0;
}