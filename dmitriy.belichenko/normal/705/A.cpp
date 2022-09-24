#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

static long parseans(long j, long l)
{
    string k = "";
    long cur = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}

int n;
int c=0;
int f[130][130][130];
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
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        if( i % 2 == 0)
        cout << "I hate that";
        else cout << " I love that ";
    }
    if( n % 2 )  cout << "I hate it";
     else cout << " I love it";
}