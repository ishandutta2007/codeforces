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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
const int inf=1e9+7;
int dp[5005][5005],rowsum[5005][5005];
int tomod(int n){
	n%=inf;
	return n<0?n+inf:n;
}
int main(){
	int n,t,a,b;
	scanf("%d%d%d%d",&n,&a,&b,&t);
	dp[0][a]=1;
	for(int k=a;k<=n;k++)rowsum[0][k]=1;
	rep1(i,t){
		rowsum[i][0]=0;
		rep1(j,n){
			if(j<b)dp[i][j]=tomod(rowsum[i-1][j+(b-j-1)/2]-dp[i-1][j]);
			else if(j>b)dp[i][j]=tomod(rowsum[i-1][n]-rowsum[i-1][j-(j-b+1)/2]-dp[i-1][j]);
		}
		rep1(j,n)rowsum[i][j]=(rowsum[i][j-1]+dp[i][j])%inf;
	}
	int ans=0;
	rep1(k,n)
	if(k!=b)ans=(ans+dp[t][k])%inf;
	printf("%d",ans);
	return 0;
}