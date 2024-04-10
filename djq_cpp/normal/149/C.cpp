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
pii ply[100005];
int main(){
	int n;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&(ply[k].first));
		ply[k].second=k+1;
	}
	sort(ply,ply+n);
	printf("%d\n",(n+1)/2);
	for(int k=0;k<n;k+=2)
	printf("%d ",ply[k].second);
	printf("\n%d\n",n/2);
	for(int k=1;k<n;k+=2)
	printf("%d ",ply[k].second);
	return 0;
}