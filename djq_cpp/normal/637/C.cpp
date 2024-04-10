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
#include <windows.h>
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
const int inf=0x3fffffff;
using namespace std;
char nums[1005][7];
int n,res;
int distan(int a,int b){
	int sum=0;
	rep(k,6)if(nums[a][k]!=nums[b][k])sum++;
	return sum;
}
int main(){
	scanf("%d",&n);
	rep(k,n)scanf("%s",nums[k]);
	if(n==1){
		printf("6");
		return 0;
	}
	res=inf;
	rep(i,n)rep(j,n)
	if(i!=j)res=min(res,distan(i,j));
	printf("%d",(int)((res-1)/2));
	return 0;
}