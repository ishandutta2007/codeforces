#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, used[250005], a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 1; i <= n * k; i++)
            used[i] = 0;

        int x = 1;
        int F = 1;

        for(int i = 0; i < n; i++)
        {
            while(used[x])
                x++;

            if(x + 2 * (k - 1) > n * k)
            {
                F = 0;
                break;
            }

            for(int j = x; j < x + 2 * k; j += 2)
            {
                used[j] = 1;
                a[i][(j - x) / 2] = j;
            }
        }

        if(F)
        {
            cout << "YES\n";

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < k; j++)
                    cout << a[i][j] << ' ';

                cout << "\n";
            }
        }
        else cout << "NO\n";
    }
}