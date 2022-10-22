#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[1005];
char b[3005][3005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 1500, y = 0;

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            while(a[i]--)
            {
                b[x][y] = '/';
                x--;
                y++;
            }

            x++;
        }
        else
        {
            while(a[i]--)
            {
                b[x][y] = '\\';
                x++;
                y++;
            }

            x--;
        }
    }

    int xmin = 1e9, xmax = -1e9, ymin = 1e9, ymax = -1e9;

    for(int i = 0; i < 3005; i++)
        for(int j = 0; j < 3005; j++)
            if(b[i][j] == '/' || b[i][j] == '\\')
            {
                xmin = min(xmin, i);
                xmax = max(xmax, i);
                ymin = min(ymin, j);
                ymax = max(ymax, j);
            }

    for(int i = xmin; i <= xmax; i++)
    {
        for(int j = ymin; j <= ymax; j++)
        {
            if(b[i][j] == '/')
                cout << '/';
            else if(b[i][j] == '\\')
                cout << '\\';
            else cout << ' ';
        }

        if(i < xmax)
            cout << "\n";
    }
}