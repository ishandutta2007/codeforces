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
int num[1000005];
ll dp[2][1000005];
int hi_lo[1000005];
int lst[1000005],nxt[1000005];
ll Abs(ll num){
	return num<0?-num:num;
}
int main(){
	int n;
	scanf("%d",&n);
	rep(k,n)scanf("%d",&num[k]);
	lst[0]=0;
	for(int k=1;k<n-1;k++)
	if(num[k]==num[k-1])lst[k]=lst[k-1];
	else lst[k]=k;
	nxt[n-1]=n-1;
	for(int k=n-2;k>=0;k--)
	if(num[k]==num[k+1])nxt[k]=nxt[k+1];
	else nxt[k]=k;
	if(nxt[0]!=n-1)
	for(int k=1;k<n-1;k++){
		if(num[lst[k]-1]<num[k]&&num[nxt[k]+1]<num[k])hi_lo[k]=1;
		else if(num[lst[k]-1]>num[k]&&num[nxt[k]+1]>num[k])hi_lo[k]=-1;
	}
	for(int k=1;k<n;k++){
		ll subn=Abs(ll(num[k]-num[k-1]));
		if(!hi_lo[k]&&!hi_lo[k-1])
			dp[0][k]=dp[0][k-1]+subn;
		else if(hi_lo[k]&&!hi_lo[k-1]){
			dp[0][k]=dp[0][k-1]+subn;
			dp[1][k]=dp[0][k-1];
		}else if(!hi_lo[k]&&hi_lo[k-1])
			dp[0][k]=max(dp[0][k-1],dp[1][k-1]+subn);
		else if(hi_lo[k]&&hi_lo[k-1]){
			if(hi_lo[k]==hi_lo[k-1])
				dp[0][k]=dp[1][k]=max(dp[0][k-1],dp[1][k-1]);
			else{
				dp[0][k]=max(dp[0][k-1],dp[1][k-1]+subn);
				dp[1][k]=max(dp[0][k-1],dp[1][k-1]);
			}
		}
	}
	printf("%I64d",max(dp[0][n-1],dp[1][n-1]));
	return 0;
}