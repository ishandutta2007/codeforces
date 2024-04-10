#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
ld p[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);

    ld ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        ld y = 0;

        for(int j = i; j < n; j++)
        {
            ld dy = p[j];

            for(int k = i; k < n; k++)
                if(k != j)
                    dy *= 1 - p[k];

            y += dy;
        }

        ans = max(ans, y);
    }

    cout << setprecision(15) << ans;
}