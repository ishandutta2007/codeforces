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
pii a[100005];
int b[100005];
int main(){
	int n;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&a[k].first);
		a[k].first*=-1;
		a[k].second=k+1;
	}
	sort(a,a+n);
	rep1(k,n)scanf("%d",&b[k]);
	printf("%d\n",n/2+1);
	printf("%d ",a[0].second);
	for(int k=1;k+1<n;k+=2){
		int i1=a[k].second,i2=a[k+1].second;
		if(b[i1]<b[i2])printf("%d ",i2);
		else printf("%d ",i1);
	}
	if(!(n&1))printf("%d ",a[n-1].second);
	return 0;
}
/*
a  
;
n=;
2;
;
:
b 
b 
a 2 
*/