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
    int n , c;
    cin >> n >> c;
    vector<int>a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i)
        {
            if(a[i] - a[i-1] > c) cnt = 0;
            else cnt++;
        }
    }
    cout <<cnt + 1 << "\n";
}