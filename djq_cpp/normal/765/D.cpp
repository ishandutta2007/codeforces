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
vector<int> v[100005];
int g[100005],h[100005],f[100005],id[100005];
set<int> H;
int main(){
	int n,m=0;
	scanf("%d",&n);
	rep1(k,n)scanf("%d",&f[k]);
	rep1(k,n){
		if(f[f[k]]!=f[k]){
			printf("-1");
			return 0;
		}
		H.insert(f[k]);
	}
	for(set<int>::iterator it=H.begin();it!=H.end();it++){
		h[++m]=*it;
		id[*it]=m;
	}
	rep1(k,n)g[k]=id[f[k]];
	printf("%d\n",m);
	rep1(k,n)printf("%d ",g[k]);putchar('\n');
	rep1(k,m)printf("%d ",h[k]);
	return 0;
}