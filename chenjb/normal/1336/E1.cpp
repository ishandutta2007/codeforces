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
#define inf 998244353
using namespace std;
#define ll long long
#define mod 998244353

long long base[60];
long long f[200000][60];
long long ans[100];
long long q1[10000],q2[10000];
int n,half;

long long mypow(long long x,long long y) 
{ 
    long long ret=1;
    while (y)
    {
        if (y&1)ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
void fwt()
{
    for(int w=2;w<=(1<<half);w<<=1) 
    for(int k=0;k<(1<<half);k+=w)
    for(int j=k;j<k+(w>>1);j++)
    for(int l=n;l;l--) 
    {
        (f[j][l]+=f[j+(w>>1)][l-1])%=mod;
        (f[j+(w>>1)][l]+=f[j][l-1])%=mod;
        // 
    }
}
int main()
{
    int tot;
    cin>>tot>>n;

    if (n==0){ cout<<mypow(2,tot)<<endl; return 0; }
    for(int i=1;i<=tot;i++)
    {
        long long x;
        scanf("%lld",&x);
        for(int i=n-1;~i;i--)  //find xor_basis
            if ((x>>i)&1)
            {
                if (!base[i]) { base[i]=x; break; }
                x^=base[i];
            }
    }

    half=n>>1; if (half==0)half++;

    int cnt1=0,cnt2=0;

    for(int i=0;i<n;i++) 
        if (base[i])
        {
            if (i>=half)q1[++cnt1]=base[i];
            else q2[++cnt2]=base[i];
        }

    int full1=(1<<cnt1)-1,full2=(1<<cnt2)-1;
    for(int i=0;i<=full1;i++)
    {
        long long now=0;
        for(int j=1;j<=cnt1;j++) 
            if (i & (1<<(j-1)))now^=q1[j];
        f[now & ((1ll<<half)-1)][bit(now>>half)]++;
    }

    fwt();

    for(int i=0;i<=full2;i++)
    {
        long long now=0;
        for(int j=1;j<=cnt2;j++) 
            if (i & (1<<(j-1)))now^=q2[j];
        for(int j=0;j<=n;j++)(ans[j]+=f[now][j])%=mod;
    }    
    
    for(int i=0;i<n;i++) 
        if (base[i])tot--;
    for (int i=0;i<=n;i++)printf("%lld ",ans[i]*mypow(2,tot)%mod);
    puts("");
    return 0;
}