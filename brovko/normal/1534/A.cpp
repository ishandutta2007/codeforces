#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, m;
char a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int w0 = 0, w1 = 0, r0 = 0, r1 = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
        {
            if((i + j) % 2 == 0 && a[i][j] == 'W')
                w0++;

            if((i + j) % 2 == 1 && a[i][j] == 'W')
                w1++;

            if((i + j) % 2 == 0 && a[i][j] == 'R')
                r0++;

            if((i + j) % 2 == 1 && a[i][j] == 'R')
                r1++;
        }

        if(r1 + w0 == 0)
        {
            cout << "YES\n";

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                    if((i + j) % 2 == 0)
                        cout << 'R';
                    else cout << 'W';

                cout << "\n";
            }
        }
        else
        if(w1 + r0 == 0)
        {
            cout << "YES\n";

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                    if((i + j) % 2 == 1)
                        cout << 'R';
                    else cout << 'W';

                cout << "\n";
            }
        }
        else cout << "NO\n";
    }
}