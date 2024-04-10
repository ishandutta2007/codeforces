#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, q, x[250005], y[250005], t[250005], ps[505][505], a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> q;

    for(int i = 0; i < q; i++)
        cin >> x[i] >> y[i] >> t[i];

    int L = -1;
    int R = 2e9;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        for(int i = 0; i < 505; i++)
            for(int j = 0; j < 505; j++)
        {
            a[i][j] = 0;
            ps[i][j] = 0;
        }

        for(int i = 0; i < q; i++)
            if(t[i] <= M)
                a[x[i]][y[i]]++;

        for(int i = 1; i < 505; i++)
            for(int j = 1; j < 505; j++)
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + a[i][j];

        int f = 0;

        /*for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
                cout << ps[i][j] << ' ';
            cout << endl;
        }
        return 0;*/

        for(int i = k; i < 505; i++)
            for(int j = k; j < 505; j++)
                if(ps[i][j] - ps[i][j - k] - ps[i - k][j] + ps[i - k][j - k] == k * k)
                    f = 1;

        if(f)
            R = M;
        else L = M;
    }

    if(R == 2e9)
        cout << -1;
    else cout << R;
}