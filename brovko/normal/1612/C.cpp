#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, k, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> k >> c;

        int L = 0, R = 2 * k - 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int x = M * (M + 1) / 2;

            if(M > k)
                x = k * k - (2 * k - 1 - M) * (2 * k - M) / 2;

            if(x >= c)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}