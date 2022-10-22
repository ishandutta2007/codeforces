#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[45];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int g = 0;

        for(int i = 1; i < n; i++)
            g = __gcd(g, abs(a[i] - a[i - 1]));

        if(g == 0)
            cout << "-1\n";
        else cout << g << "\n";
    }
}