#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[105];

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

        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
            {
                ans += j - i + 1;

                for(int z = i; z <= j; z++)
                    ans += (a[z] == 0);
            }

        cout << ans << "\n";
    }
}