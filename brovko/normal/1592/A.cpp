#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int t, n, h, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> h;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int L = -1, R = 2e9;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(a[n - 2] * (M / 2) + a[n - 1] * (M - M / 2) >= h)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}