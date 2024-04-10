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
#define inf 998244353
#define rep(i,n) for(int i=1;i<=n;++i)
#define bit(i) __builtin_popcount(i)
#define N 4100000
#define M 510000
using namespace std;
int T;
int a[N],q[N],id[N],ans[N];
int n,m;
int get(int x)
{
    int l=x*2;
    int r=x*2+1;
    if (l>=(1<<n) || !a[l]) l=0;
    if (r>=(1<<n) || !a[r]) r=0;
    if (!l && !r) return x;
    if (a[l]>a[r]) return get(l);
    else return get(r);
}
void dfs(int x)
{
    int l=x*2;
    int r=x*2+1;
    if (l>=(1<<n) || !a[l]) l=0;
    if (r>=(1<<n) || !a[r]) r=0;
    if (!l && !r) { a[x]=0;return; }
    if (a[l]>a[r])
    { 
        a[x]=a[l];
        id[a[x]]=x;
        dfs(l);
    }
    else
    {
        a[x]=a[r];
        id[a[x]]=x;
        dfs(r);
    }
    
}
bool check(int ti,int x)
{
    if (a[id[x]]!=x)return 0;
    if (get(id[x])<(1<<m))return 0;
    ans[ti]=id[x];
    dfs(id[x]);
    return 1;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<(1<<n);i++)scanf("%d",&a[i]),q[i]=a[i];
        sort(q+1,q+(1<<n));
        for (int i=1;i<(1<<n);i++)
        {
            a[i]=lower_bound(q+1,q+(1<<n),a[i])-q;
            id[a[i]]=i;
        }
        int delta=(1<<n)-(1<<m);
        for (int i=1,now=(1<<n)-1;i<=delta;i++)
            while (!check(i,now))now--;
        long long sum=0;
        for (int i=1;i<(1<<m);i++)sum+=q[a[i]];
        printf("%lld\n",sum);
        for (int i=1;i<=delta;i++)printf("%d ",ans[i]);
        puts(""); 
    }
    
}