#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, r[200005], c[200005];

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
            cin >> r[i];

        for(int i = 0; i < n; i++)
            cin >> c[i];

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.push_back({r[i], c[i]});

        v.push_back({1, 1});

        sort(v.begin(), v.end());

        for(int i = 0; i <= n; i++)
        {
            r[i] = v[i].x;
            c[i] = v[i].y;
        }

        int ans = 0;

        for(int i = 1; i < n + 1; i++)
        {
            if((r[i - 1] + c[i - 1]) % 2 == 0)
            {
                if(r[i] - r[i - 1] == c[i] - c[i - 1])
                {
                    ans += r[i] - r[i - 1];
                    continue;
                }

                r[i - 1]++;
            }

            r[i - 1] += c[i] - c[i - 1];

            ans += (r[i] - r[i - 1] + 1) / 2;
        }

        cout << ans << "\n";
    }
}