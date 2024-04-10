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
ll num[4];
bool del[4];
char op[3];
ll dfs(int dep){
	if(dep==3){
		rep(k,4)
		if(!del[k])return num[k];
	}
	ll ans=1e16+7;
	rep(i,4)if(!del[i])
	rep(j,4)if(!del[j]&&i!=j){
		del[j]=true;
		ll oldn=num[i];
		if(op[dep]=='*')num[i]*=num[j];
		if(op[dep]=='+')num[i]+=num[j];
		ans=min(ans,dfs(dep+1));
		num[i]=oldn;
		del[j]=false;
	}
	return ans;
}
int main(){
	rep(k,4)cin>>num[k];
	rep(k,3)cin>>op[k];
	printf("%I64d",dfs(0));
	return 0;
}