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
ll sqrt3(ll ori){
	ll L=0,R=1e6+1;
	while(L<R){
		ll mid=(L+R)>>1;
		if(mid*mid*mid>=ori)R=mid;
		else L=mid+1;
	}
	return R;
}
int main(){
	int n;
	ll x,y;
	scanf("%d",&n);
	rep(k,n){
		scanf("%I64d%I64d",&x,&y);
		ll s=sqrt3(x*y);
		if(s*s*s==x*y&&s*s%x==0&&s*s%y==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}