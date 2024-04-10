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

int n;
long long x1 , x2;
int main()
{
       cin >> n;
       vector<pair<long long , long long > > t(n);
       cin >> x1 >> x2;
    for(int i = 0; i < n; i++)
    {
        long long k , b;
        cin >> k >> b;
        t[i].first = k * x1 + b;
        t[i].second = k * x2 + b;
    }
    sort(t.begin() , t.end());
    for(int i = 0; i < n - 1; i++)
    {
        if(t[i].second > t[i+1].second && t[i].first != t[i+1].first)
        {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
   
       return 0;
}