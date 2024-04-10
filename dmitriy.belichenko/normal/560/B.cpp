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

int cur = 1;
int cnt = 0;
static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    } else
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
int n , k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a , b , a1 , b1 , a2 , b2;
    cin >> a >> b >> a1 >> b1 >> a2 >> b2;
    int k = a;
    a = min(k , b);
    b = max(k , b);
    int k1 = a1;
    a1 = min(k1 , b1);
    b1 = max(k1 , b1);
    int k2 = a2;
    a2 = min(k2 , b2);
    b2 = max(k2 , b2);
    if( a1 + a2 <= a && max(b1 , b2) <= b)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( b1 + b2 <= b && max(a1 , a2) <= a)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( a1 + b2 <= b && max(b1 , a2) <= a)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( b1 + a2 <= b && max(b2 , a1) <= a)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( b1 + a2 <= a && max(b2 , a1) <= b)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( a1 + b2 <= a && max(b1 , a2) <= b)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( a1 + a2 <= b && max(b1 , b2) <= a)
    {
        cout << "YES" << "\n";
        return 0;
    }
    if( b1 + b2 <= a && max(a1 , a2) <= b)
    {
        cout << "YES" << "\n";
        return 0;
    }


    cout << "NO" << "\n";
}