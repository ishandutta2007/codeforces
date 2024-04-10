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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	if(x==0&&n%4==2){
		if(n==2)printf("NO\n");
		else{
			printf("YES\n");
			printf("0 1 2 7 8 12 ");
			n-=6;
			for(int k=0;k<n;k+=4)printf("%d %d %d %d ",200000+k,200001+k,200002+k,200003+k);
		}
		return 0;
	}
	printf("YES\n");
	for(int k=0;k+4<n;k+=4)
	printf("%d %d %d %d ",200000+k,200001+k,200002+k,200003+k);
	n%=4;
	if(n==0)n=4;
	if(x>=4){
		rep(k,n-1)printf("%d ",k);
		rep(k,n-1)x^=k;
		printf("%d",x);
	}else{
		if(n==4)printf("0 %d 8 12",x+4);
		if(n==3)printf("%d 8 12",x+4);
		if(n==2)printf("0 %d",x);
		if(n==1)printf("%d",x);
	}
	return 0;
}