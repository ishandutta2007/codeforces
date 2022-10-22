#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, l, r, ps[200005][20];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < 200005; i++)
        for(int j = 0; j < 20; j++)
            ps[i][j] = ps[i - 1][j] + (bool)(i & (1 << j));

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        int Max = 0;

        for(int i = 0; i < 20; i++)
            Max = max(Max, ps[r][i] - ps[l - 1][i]);

        cout << r - l + 1 - Max << "\n";
    }
}