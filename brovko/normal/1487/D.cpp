#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int L = 0, R = 1e9;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if((M * M + 1) / 2 <= n)
                L = M;
            else R = M;
        }

        cout << (L - 1) / 2 << "\n";
    }
}