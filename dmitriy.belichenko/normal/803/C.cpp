#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;

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
long long n , k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
       deque<long long> fact;
    for(long long i = 1; i * i <=n; i++)
    {
        if(n % i == 0)
        {
            fact.push_back(i);
            fact.push_front(n/i);
        }
    }
   
    sort(fact.rbegin(), fact.rend());
    for(int i = 0; i < fact.size(); i++)
    {
        if(  (1LL + k) * k * fact[i] / 2 <= n &&  (1LL + k) * k * fact[i] / 2  > 0 && k <= 100000000)
        {
            for(long long j = 0; j < k - 1; j++)
            {
                cout << (long long)(j+1LL)*fact[i] << " ";
                n -= fact[i]*(j+1LL);
            }
            cout << n;
            return 0;
        }
    }
    cout << -1;
    cout << "\n";
}