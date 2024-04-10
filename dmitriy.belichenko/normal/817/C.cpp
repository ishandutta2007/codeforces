#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
long long inf = 1LL << 62;
static long parseans(long j, long l)
{
    string k = "";
    long ps = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        ps *= 10;
        ps += k[i] - '0';
    }
    return ps;
}
long long n , s;

bool check(long long m , long long s)
{
    long long k = m;
    long long sum = 0;
    while(k > 0)
    {
        sum += k % 10;
        k = k / 10;
    }
    if(m - sum >= s) return 1;
    return 0;
}
int cur = 1;
int cnt = 0;
static long gcd(long a, long b)
{
    if (b == 0)
    {
      return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(20);
    cin >> n >> s;
    long long l = 1;
    long long r = n + 1;
    long long mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if ( check(mid, s)) r = mid - 1;
        else l = mid;
    }
    cout <<max( n - l , 0LL) << "\n";
}