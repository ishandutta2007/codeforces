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
#define bit(i) __builtin_popcount(i)
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
using namespace std;
int n,m,k;
long long a[510000],b[510000],c[510000];
long long ans;
void work(long long a[],long long b[],long long c[])
{
    int n=a[0],m=b[0],k=c[0];
    
    for(int i=1;i<=n;i++)
    {
        if (a[i]<c[1] || a[i]>b[m])continue;
        int t2=upper_bound(c+1,c+k+1,a[i])-c-1;
        int t1=lower_bound(b+1,b+m+1,a[i])-b;
        ans=min(ans,(a[i]-b[t1])*(a[i]-b[t1])+(b[t1]-c[t2])*(b[t1]-c[t2])+(c[t2]-a[i])*(c[t2]-a[i]));
    }
    for(int i=1;i<=n;i++)
    {
        if (a[i]<b[1] || a[i]>c[k])continue;
        int t1=upper_bound(b+1,b+m+1,a[i])-b-1;
        int t2=lower_bound(c+1,c+k+1,a[i])-c;
        ans=min(ans,(a[i]-b[t1])*(a[i]-b[t1])+(b[t1]-c[t2])*(b[t1]-c[t2])+(c[t2]-a[i])*(c[t2]-a[i]));
    }
}

int main()
{
    int T;
    cin>>T;
    while(T --)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]); a[0]=n;
        for(int i=1;i<=m;i++)scanf("%lld",&b[i]); b[0]=m;
        for(int i=1;i<=k;i++)scanf("%lld",&c[i]); c[0]=k;
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        sort(c+1,c+k+1);
        ans=(a[1]-b[1])*(a[1]-b[1])+(b[1]-c[1])*(b[1]-c[1])+(c[1]-a[1])*(c[1]-a[1]);
        work(a,b,c);
        work(b,c,a);
        work(c,a,b);
        printf("%lld\n",ans);
    }
    return 0;
}