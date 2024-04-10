#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        if(k > (n + 1) / 2)
            cout << "-1\n";
        else
        {
            int a[n][n];

            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    a[i][j] = 0;

            for(int i = 0; i < 2 * k; i += 2)
                a[i][i] = 1;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(a[i][j])
                        cout << 'R';
                    else cout << '.';
                }

                cout << "\n";
            }
        }
    }
}