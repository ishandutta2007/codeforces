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
bitset<505> dp[505];
int main(){
	int n,mv,num;
	scanf("%d%d",&n,&mv);
	dp[0][0]=true;
	rep(k,n){
		scanf("%d",&num);
		for(int v=mv;v>=num;v--)dp[v]|=dp[v-num]|(dp[v-num]<<num);
	}
	vector<int> ans;
	for(int k=0;k<=mv;k++)
	if(dp[mv][k])ans.push_back(k);
	printf("%d\n",ans.size());
	rep(k,ans.size())
	printf("%d ",ans[k]);
	return 0;
}