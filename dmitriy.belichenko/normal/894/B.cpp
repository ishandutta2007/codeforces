#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;
pair<int,int> a[22];
int b[22];
long long MOD = 1e9 + 7;
unsigned long long biow (long long a, long long n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return  ( ((biow(a, n-1)% MOD) * (a % MOD)) % MOD);
    else {
        unsigned long long b = (1ULL * biow (a, n/2) % MOD);
        return ((b % MOD) * (b % MOD)) % MOD;
    }
}
long long poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    long long n , m , k;
    cin >> n >> m >> k;
    if( n % 2 != m % 2 && k != 1 && n % 2 == 1)
    {
        cout << 0 ;
        return 0;
    }
    if( n % 2 != m % 2 && k != 1 && n % 2 == 0)
    {
        cout << 0 ;
        return 0;
    }
    long long st1 = ( n - 1) % (MOD - 1);
    long long st2 =  ( m - 1) % (MOD  - 1);
    long long st = ( st1 * st2) % (MOD - 1);
    cout << poww(2 , st);
}