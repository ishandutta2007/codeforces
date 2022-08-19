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
char grid[1005][1005];
int Rs[1005],Cs[1005];
int main(){
	int n,m,Bs,Sum=0;
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%s",grid[i]);
		rep(j,m)if(grid[i][j]=='*'){
			Rs[i]++;Cs[j]++;
			Sum++;
		}
	}
	rep(i,n)rep(j,m){
		Bs=Rs[i]+Cs[j]+(grid[i][j]=='*'?-1:0);
		if(Bs==Sum){
			printf("YES\n%d %d",i+1,j+1);
			return 0;
		}
	}
	printf("NO");
	return 0;
}