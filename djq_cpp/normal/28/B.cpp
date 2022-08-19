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
using namespace std;
int lined[505][505];
int num[505];
int main(){
	int n,in;
	scanf("%d",&n);
	rep1(k,n)scanf("%d",&num[k]);
	rep1(k,n){
		scanf("%d",&in);
		if(k>in)lined[k][k-in]=lined[k-in][k]=true;
		if(k+in<=n)lined[k][k+in]=lined[k+in][k]=true;
	}
	rep1(k,n)lined[k][k]=true;
	rep1(k,n)rep1(i,n)rep1(j,n)
	if(lined[i][k]&&lined[k][j])
	lined[i][j]=lined[j][i]=true;
	rep1(k,n)
	if(!lined[num[k]][k]){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}