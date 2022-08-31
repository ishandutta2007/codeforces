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
#define cindy(i,n) for(int i=0;i<(n);i++)
#define cindy1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
char grid[105][105];
int B,lx=INF,rx=-1,ly=INF,ry=-1;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	cindy(k,n)scanf("%s",grid[k]);
	cindy(i,n)cindy(j,m)
	if(grid[i][j]=='B'){
		B++;
		lx=min(lx,i);
		rx=max(rx,i);
		ly=min(ly,j);
		ry=max(ry,j);
	}
	if(rx==-1){
		printf("1");
		return 0;
	}
	int d=max(rx-lx+1,ry-ly+1);
	if(d>m||d>n)printf("-1");
	else printf("%d",d*d-B);
	return 0;
}