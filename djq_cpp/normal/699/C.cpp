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
int ok[105],dp[105][3];
int main(){
	int n;
	scanf("%d",&n);
	rep1(k,n)scanf("%d",&ok[k]);
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	rep1(k,n){
		dp[k][0]=max(dp[k-1][0],max(dp[k-1][1],dp[k-1][2]));
		if(ok[k]&1)dp[k][1]=max(dp[k-1][0],dp[k-1][2])+1;
		if(ok[k]&2)dp[k][2]=max(dp[k-1][0],dp[k-1][1])+1;
	}
	printf("%d",n-max(dp[n][0],max(dp[n][1],dp[n][2])));
	return 0;
}