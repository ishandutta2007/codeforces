#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n][n];

        for(int j = 0; j < n; j++)
            for(int i = 0; i < n; i++)
        {
            if(k)
                a[i][(i + j) % n] = 1;
            else a[i][(i + j) % n] = 0;

            if(k)
                k--;
        }

        int maxr = 0, minr = n;

        for(int i = 0; i < n; i++)
        {
            int r = 0;

            for(int j = 0; j < n; j++)
            {
                r += a[i][j];
            }

            maxr = max(maxr, r);
            minr = min(minr, r);
        }

        int maxc = 0, minc = n;

        for(int i = 0; i < n; i++)
        {
            int c = 0;

            for(int j = 0; j < n; j++)
            {
                c += a[j][i];
            }

            maxc = max(maxc, c);
            minc = min(minc, c);
        }

        cout << (maxc - minc) * (maxc - minc) + (maxr - minr) * (maxr - minr) << "\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j];
            cout << "\n";
        }
    }
}