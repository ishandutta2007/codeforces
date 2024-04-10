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
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
int n , k;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    deque<int> c , d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n/2; i++) c.push_back(a[i]);
    for(int i = n/2; i < n; i++) d.push_back(a[i]);
    sort(d.rbegin(), d.rend());
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0 && c.size())
        {
            cout << c[0] << " ";
            c.pop_front();
        }
        else if(d.size())
        {
            cout << d[0] << " ";
            d.pop_front();
         }
    }
}