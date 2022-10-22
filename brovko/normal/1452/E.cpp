#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k, l[2005], r[2005];

int f(int x, int y)
{
    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        ans += max({0, min(x + k - 1, r[i]) - max(x, l[i]) + 1, min(y + k - 1, r[i]) - max(y, l[i]) + 1});
//        cout << "!" << i << ' ' << max({0, min(x + k - 1, r[i]) - max(x, l[i]) + 1, min(y + k - 1, r[i]) - max(y, l[i]) + 1}) << endl;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        vector <int> a(n + 1);

        for(int j = 0; j < m; j++)
        {
            int I = max(i, l[j] - k);

            if(i >= l[j] || i >= r[j] - k + 1)
                continue;

            int p = l[j] + r[j] - I;

            a[I]++;
            a[l[j]]--;
            a[r[j] - k + 1]--;
            a[p - k + 1]++;
        }

        vector <int> x(n + 1);

        int V = 0;
        int X = 0;

        for(int j = 0; j < n; j++)
        {
            X += V;
            V += a[j];

            x[j] = X;
        }

        int F = f(i, i);

        for(int j = 0; j < n; j++)
            ans = max(ans, F + x[j]);
    }

    cout << ans;
}