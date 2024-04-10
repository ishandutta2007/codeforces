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
    vector<int>a(n);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n;i++)
    {
        cin >> a[i];
        if(a[i] == 1 && !cnt1 && !cnt2) cout << 2 << "\n";
        else
        {
        if(a[i] % 2 ) cnt1++;
        else cnt2++;
           if(cnt2 % 2 == 0 ) cout << 2 << "\n";
            else cout << 1 << "\n";
        }
    }
}