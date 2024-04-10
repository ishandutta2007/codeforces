#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

bool prime(int x)
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;

    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int m = n;

    while(!prime(m))
        m--;

    if(m == n)
    {
        cout << 1 << "\n" << m;
        return 0;
    }

    n -= m;

    if(prime(n))
    {
        cout << 2 << "\n" << m << ' ' << n;
        return 0;
    }

    for(int i = 2; i < n - 1; i++)
        if(prime(i) && prime(n - i))
        {
            cout << 3 << "\n" << m << ' ' << i << ' ' << n - i;
            return 0;
        }
}