#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int k[4], a[200005][4], Min[4], Max[4];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int w, h;
        cin >> w >> h;

        for(int i = 0; i < 4; i++)
        {
            Min[i] = 1e9;
            Max[i] = -1e9;

            cin >> k[i];

            for(int j = 0; j < k[i]; j++)
            {
                cin >> a[j][i];

                Min[i] = min(Min[i], a[j][i]);
                Max[i] = max(Max[i], a[j][i]);
            }
        }

        cout << max({(Max[0] - Min[0]) * h, (Max[1] - Min[1]) * h, (Max[2] - Min[2]) * w, (Max[3] - Min[3]) * w}) << "\n";
    }
}