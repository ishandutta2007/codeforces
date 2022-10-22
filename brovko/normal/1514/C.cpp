#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int p = 1, k = 0;

    for(int i = 1; i <= n; i++)
        if(gcd(i, n) == 1)
        {
            p = p * i % n;
            k++;
        }

    if(p == 1)
    {
        cout << k << endl;

        for(int i = 1; i <= n; i++)
            if(gcd(i, n) == 1)
                cout << i << ' ';
    }
    else
    {
        cout << k - 1 << endl;

        for(int i = 1; i <= n; i++)
            if(gcd(i, n) == 1 && i != p)
                cout << i << ' ';
    }
}