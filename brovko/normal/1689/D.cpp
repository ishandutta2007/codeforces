#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

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
        int n, m;
        cin >> n >> m;

        char a[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int L = -1, R = 5000;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int Mins = -1e9, Mind = -1e9, Maxs = 1e9, Maxd = 1e9;

            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(a[i][j] == 'B')
                    {
                        Mins = max(Mins, i + j - M);
                        Maxs = min(Maxs, i + j + M);

                        Mind = max(Mind, i - j - M);
                        Maxd = min(Maxd, i - j + M);
                    }

            bool F = false;

            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(i + j >= Mins && i + j <= Maxs && i - j >= Mind && i - j <= Maxd)
                        F = true;

            if(F)
                R = M;
            else L = M;
        }

        int Mins = -1e9, Mind = -1e9, Maxs = 1e9, Maxd = 1e9;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] == 'B')
                {
                    Mins = max(Mins, i + j - R);
                    Maxs = min(Maxs, i + j + R);

                    Mind = max(Mind, i - j - R);
                    Maxd = min(Maxd, i - j + R);
                }

        int x = -1, y = -1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(i + j >= Mins && i + j <= Maxs && i - j >= Mind && i - j <= Maxd)
                {
                    x = i;
                    y = j;
                }

        assert(x > -1);

        cout << x + 1 << ' ' << y + 1 << "\n";
    }
}