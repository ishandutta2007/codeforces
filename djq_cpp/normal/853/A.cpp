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
pii fli[300005];
int ans[300005];
set<int> T;
int main(){
	int n,t;
	ll cnt=0LL;
	scanf("%d%d",&n,&t);
	rep(k,n)T.insert(k+t);
	rep(k,n)scanf("%d",&fli[k].first);
	rep(k,n)fli[k].second=k;
	rep(k,n)fli[k].first*=-1;
	sort(fli,fli+n);
	rep(k,n){
		set<int>::iterator it=T.lower_bound(fli[k].second);
		ans[fli[k].second]=*it;
		cnt-=ll(fli[k].first)*(ans[fli[k].second]-fli[k].second);
		T.erase(it);
	}
	printf("%I64d\n",cnt);
	rep(k,n)printf("%d ",ans[k]+1);
	return 0;
}