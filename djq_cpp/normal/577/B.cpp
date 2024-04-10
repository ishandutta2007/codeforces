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
#include <conio.h>
#include <memory.h>
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
int ans[1005][1005];
int num[1005],m;
bool solve(int nown,int mod,int nums){
	if(nums>m)return false;
	if(mod==0&&nums!=0)return true;
	if(nown>m)return false;
	if(ans[nown][mod]!=-1)return ans[nown][mod];
	for(int k=0;k<=num[nown];k++)
	if(solve(nown+1,(mod+(k%m)*nown)%m,nums+k))return ans[nown][mod]=1;
	return ans[nown][mod]=0;
}
int main(){
	int n,p;
	scanf("%d%d",&n,&m);
	rep(k,n){
		scanf("%d",&p);
		num[p%m]++;
	}
	rep(i,m)rep(j,m)ans[i][j]=-1;
	printf(solve(0,0,0)?"YES":"NO");
	return 0;
}