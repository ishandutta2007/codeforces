#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int x = 1e6+3;
    cout << x << ' ' << x << "\n";

    for(int i=1; i<n-1; i++)
    {
        cout << i << ' ' << i+1 << ' ' << 1 << "\n";
    }

    cout << n - 1 << ' ' << n << ' ' << x - n + 2 << "\n";

    m -= n - 1;

    for(int i=1; i<n; i++)
        for(int j=i+2; j<=n; j++)
    {
        if(m == 0)
            return 0;
        cout << i << ' ' << j << ' ' << 1000000000 << "\n";
        m--;
    }
}