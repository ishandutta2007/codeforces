#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005];

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

        int L = -1, R = 2e9;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            for(int i = 0; i < n; i++)
                b[i] = a[i];

            for(int i = n - 1; i >= 2; i--)
            {
                int x = max(0ll, min(a[i], b[i] - M)) / 3;

                b[i] -= 3 * x;
                b[i - 1] += x;
                b[i - 2] += 2 * x;
            }

            int F = 1;

            for(int i = 0; i < n; i++)
                if(b[i] < M)
                    F = 0;

            if(F)
                L = M;
            else R = M;
        }

        cout << L << "\n";
    }
}