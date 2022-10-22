#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define li long long

using namespace std;

int Y[3], M[3], c[3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 3; i++)
        cin >> Y[i];

    for(int i = 0; i < 3; i++)
        cin >> M[i];

    for(int i = 0; i < 3; i++)
        cin >> c[i];

    int ans = 1e18;

    for(int a = 0; a <= 1000; a++)
        for(int d = 0; d <= 1000; d++)
        {
            int d1 = max(0ll, Y[1] + a - M[2]);
            int d2 = max(0ll, M[1] - d - Y[2]);

            if(d1 == 0)
                continue;

            if(d2 == 0)
            {
                ans = min(ans, a * c[1] + d * c[2]);
                continue;
            }

            int H = (M[0] + d1 - 1) / d1 * d2 + 1;

            ans = min(ans, a * c[1] + d * c[2] + max(0ll, H - Y[0]) * c[0]);
        }

    cout << ans;
}