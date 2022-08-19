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
	int a,b,f,k,cf,ans=0;
	scanf("%d%d%d%d",&a,&b,&f,&k);cf=b-f;
	if(cf<0){
		printf("-1");
		return 0;
	}
	rep(i,k){
		int tt=((i&1)?f:a-f)*((i==k-1)?1:2);
		if(tt>b){
			printf("-1\n");
			return 0;
		}else if(tt>cf){
			cf=b-tt;
			ans++;
		}else cf-=tt;
	}
	printf("%d\n",ans);
	return 0;
}