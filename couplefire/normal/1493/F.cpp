#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;

bool is_prime(int a)
{
    if(a == 1)
        return 0;
    for(int i = 2; i*i <= a; ++i)
        if(a%i == 0)
            return false;
    return true;
}

bool check_period_n(int p, int n, int m)
{
    int x = n/p;
    while(x < n)
    {
        if(x*2 >= n)
        {
            while(x*2 > n)
                x -= n/p;
            cout << '?' << ' ' << x << ' ' << m << ' ' << n-x*2+1 << ' ' <<1 << ' ' << n-x+1 << ' ' << 1 << '\n';
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == 0)
                return false;
            else
                return true;
        }
        cout << '?' << ' ' << x << ' ' << m << ' ' << 1 << ' ' << 1 << ' ' << 1+x << ' ' << 1 << '\n';
        cout.flush();
        int ans;
        cin >> ans;
        if(ans == 0)
            return false;
        x *= 2;
    }
    return true;
}

bool check_period_m(int p, int n, int m)
{
    int x = m/p;
    while(x < m)
    {
        if(x*2 >= m)
        {
            while(x*2 > m)
                x -= m/p;
            cout << '?' << ' ' << n << ' ' << x << ' ' << 1 << ' ' << m-x*2+1 << ' ' << 1 << ' ' << m-x+1 << '\n';
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == 0)
                return false;
            else
                return true;
        }
        cout << '?' << ' ' << n << ' ' << x << ' ' << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1+x << '\n';
        cout.flush();
        int ans;
        cin >> ans;
        if(ans == 0)
            return false;
        x *= 2;
    }
    return true;
}


int main()
{
    int n,m;
    cin >> n >> m;
    int res = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(is_prime(i))
        {
            int t = 1;
            while(n%i == 0 && check_period_n(i, n, m))
            {
                n /= i;
                ++t;
            }
            res *= t;
        }
    }
    for(int i = 2; i <= m; ++i)
    {
        if(is_prime(i))
        {
            int t = 1;
            while(m%i == 0 && check_period_m(i, n, m))
            {
                m /= i;
                ++t;
            }
            res *= t;
        }
    }
    cout << '!' << ' ' << res << '\n';
    cout.flush();
    return 0;
}