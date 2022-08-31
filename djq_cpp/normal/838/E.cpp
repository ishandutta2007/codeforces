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
double dp[2505][2505][3],dist[2505][2505],x[2505],y[2505];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(k,n)cin>>x[k]>>y[k];
	rep(i,n)rep(j,n)dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	for(int k=1;k<n;k++)
	rep(i,n){
		int j=(i+k)%n;
		int pj=(i+k-1)%n,ni=(i+1)%n;
		dp[i][j][0]=max(dp[i][pj][0]+dist[pj][j],dp[ni][j][0]+dist[i][ni]);
		dp[i][j][1]=max(max(dp[ni][j][1]+dist[i][ni],dp[ni][j][2]+dist[i][j]),dp[i][pj][0]+dist[pj][j]);
		dp[i][j][2]=max(max(dp[i][pj][2]+dist[pj][j],dp[i][pj][1]+dist[i][j]),dp[ni][j][0]+dist[i][ni]);
	}
	double ans=0.0;
	rep(i,n)rep(j,3)ans=max(ans,dp[(i+1)%n][i][j]);
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}