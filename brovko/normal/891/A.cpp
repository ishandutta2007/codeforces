#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[2005];

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
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int Min = 1e9;
    for(int i = 0; i < n; i++)
    {
        int g = 0;
        for(int j = i; j < n; j++)
        {
            g = gcd(g, a[j]);
            if(g == 1)
                Min = min(Min, j - i);
        }
    }

    if(Min == 1e9)
    {
        cout << -1;
        return 0;
    }

    int k = 0;

    for(int i = 0; i < n; i++)
        if(a[i] == 1)
            k++;

    if(k > 1)
        cout << n - k;
    else cout << Min + n - 1;
}