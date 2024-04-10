#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[50], s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;

    for(int i = 0; i < k; i++)
        {
            cin >> a[i];
            s += a[i];
        }

    int Max = 0;

    for(int i = 0; i <= n; i++)
    {
        int t = m - s * i;

        if(t >= 0)
        {
            vector <int> v;

            for(int j = 0; j < n - i; j++)
                for(int x = 0; x < k; x++)
                    v.push_back(a[x]);

            sort(v.begin(), v.end());

            int ans = i * (k + 1);

            for(auto to:v)
                if(t >= to)
            {
                t -= to;
                ans++;
            }

            Max = max(Max, ans);
        }
    }

    cout << Max;
}