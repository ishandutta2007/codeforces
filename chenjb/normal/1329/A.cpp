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
#include <numeric>
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
#define inf 998244353
#define rep(i,n) for(int i=1;i<=n;++i)
#define bit(i) __builtin_popcount(i)
#define N 2100000
#define M 510000
using namespace std;
int n,m;
long long l[N],ans[N];
long long fl[N],fr[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)scanf("%lld",&l[i]);
    for(int i=m;i>=1;i--)fr[i]=fr[i+1]+l[i];
    for(int i=m;i>=1;i--)fl[i]=max(fl[i+1]+1,l[i]);
    if (fl[1]>n || fr[1]<n)
    {
        puts("-1");
        return 0;
    }
    long long now=n;
    for(int i=1;i<=m;i++)
    {
        printf("%lld ",now-l[i]+1);
        now--;
        now=min(now,fr[i+1]);
    }
    puts("");
    return 0;
}