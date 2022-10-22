#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[5005], d[5005], ps[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= i; j++)
            if(ps[j] > ps[d[i]])
                d[i] = j;


    int d1 = 0;
    int d2 = 0;
    int d3 = 0;

    for(int i = 0; i <= n; i++)
        for(int j = i; j <= n; j++)
    {
        int k = d[i];

        if(-ps[n] + 2 * ps[j] - 2 * ps[i] + 2 * ps[k] > -ps[n] + 2 * ps[d3] - 2 * ps[d2] + 2 * ps[d1])
        {
            d1 = k;
            d2 = i;
            d3 = j;
        }
    }

    cout << d1 << ' ' << d2 << ' ' << d3;
}