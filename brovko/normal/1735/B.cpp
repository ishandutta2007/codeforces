#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int L = 0, R = 1e9;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if((a[i] + M - 1) / M < 2 * a[0])
                    R = M;
                else L = M;
            }

            ans += L;
        }

        cout << ans << "\n";
    }
}