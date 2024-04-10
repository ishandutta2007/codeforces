#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcountll(i)
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
#define N 110000
#define inf 1000000
#define pow fuck
using namespace std;
int n;
long long a[30][30];
vector<pair<int,int> > ans;
long long get(int x,int y)
{
	if (y==1)return 1ll<<62;
	long long sum=0;
	y--; 
	while (x!=1)sum+=a[x--][y];
	return sum;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[1][i]=0;
	for(int i=1;i<=n;i++)a[2][i]=1;
	for(int i=3;i<=n;i++)
	{
		a[i][1]=(1ll<<(i-2));
		for(int j=2;j<=n;j++)
			a[i][j]=a[i][j-1]+a[i-1][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)printf("%lld%c",a[i][j],j==n?'\n':' ');
	fflush(stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		long long m;
		scanf("%lld",&m); long long tm=m;
		ans.clear(); 
		int nowx=n,nowy=n;
		while (nowx!=1||nowy!=1)
		{
			m-=a[nowx][nowy];
			ans.pb(mp(nowx,nowy));
			long long t1=get(nowx,nowy);
			if (t1>m)nowx--;
			else nowy--;
		}
		ans.pb(mp(1,1));
		reverse(ans.begin(),ans.end());
		for(auto p:ans){ printf("%d %d\n",p.first,p.second); tm-=a[p.first][p.second]; }
		fflush(stdout);
		assert(tm==0);
	}
	return 0;
}