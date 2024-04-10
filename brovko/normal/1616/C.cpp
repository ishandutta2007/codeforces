#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[75];

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

        int ans = n - 1;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                int k = 0;

                for(int z = 0; z < n; z++)
                    if((a[j] - a[i]) * (j - z) != (a[j] - a[z]) * (j - i))
                        k++;

                ans = min(ans, k);
            }

        cout << ans << "\n";
    }
}