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
#define inf 998244353
using namespace std;
char s[110000],t[110000];
int n,m;
long long f[2][5000];
void update(long long &x,long long y)
{
    x+=y;
    if (x>inf)x-=inf;
}
int main()
{
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%s",t+1); m=strlen(t+1);
    long long ans=0;
    for(int j=1;j<=n+1;j++)f[0][j]=1;
    for (int i=1;i<=n;i++)
    {
        memset(f[i&1],0,sizeof(f[i&1]));
        for(int j=1;j<=n+1;j++)
        {
            if (j>m)update(f[i&1][j+1],f[(i&1)^1][j]);
            else 
            if (s[i]==t[j])update(f[i&1][j+1],f[(i&1)^1][j]);
            if (j-i>0)
            {
                if (j-i>m)update(f[i&1][j],f[(i&1)^1][j]);
                else 
                if (s[i]==t[j-i])update(f[(i&1)][j],f[(i&1)^1][j]);
            }
        }
        if (i>=m)update(ans,f[i&1][i+1]);
    }
    cout<<ans<<endl;
    return 0;
}