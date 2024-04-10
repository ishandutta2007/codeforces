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
vector<int> f[105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(k,m){
		int id,cf;
		scanf("%d%d",&id,&cf);
		f[cf].push_back(id);
	}
	int ans=-1;
	for(int ff=1;ff<=101;ff++){
		bool fg=true;
		rep1(i,100)rep(j,f[i].size())
		if(f[i][j]<=(i-1)*ff||f[i][j]>i*ff)fg=false;
		if(fg){
			int ca=(n-1)/ff+1;
			if(ans==-1)ans=ca;
			else if(ans!=ca){
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}