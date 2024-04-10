#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < 2 * n; i++)
            cin >> a[i];

        vector <int> c, nc;

        for(int i = 0; i < 2 * n; i++)
            if(a[i] % 2 == 0)
                c.push_back(i + 1);
                    else nc.push_back(i + 1);

        int x = 0;
        int k = 0;
        int y = 0;

        while(x + 1 < c.size() && k < n - 1)
        {
            cout << c[x] << ' ' << c[x + 1] << "\n";
            x += 2;
            k++;
        }

        while(y + 1 < nc.size() && k < n - 1)
        {
            cout << nc[y] << ' ' << nc[y + 1] << "\n";
            y += 2;
            k++;
        }
    }
}