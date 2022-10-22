#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[500005], lp[10000005], d1[500005], d2[500005];

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

    for(int i = 2; i * i < 10000005; i++)
        if(lp[i] == 0)
            for(int j = i * i; j < 10000005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        int d = lp[a[i]];
        int x = a[i];

        d1[i] = 2;
        d2[i] = 2;

        while(d > 0 && x % d == 0 && x > d)
        {
            x /= d;
        }

        d1[i] = x;
        d2[i] = d;
    }

    for(int i = 0; i < n; i++)
    {
        if(gcd(d1[i] + d2[i], a[i]) == 1)
            cout << d1[i] << ' ';
        else cout << -1 << ' ';
    }

    cout << "\n";

    for(int i = 0; i < n; i++)
    {
        if(gcd(d1[i] + d2[i], a[i]) == 1)
            cout << d2[i] << ' ';
        else cout << -1 << ' ';
    }
}