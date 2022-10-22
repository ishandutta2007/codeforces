#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[505], k, b[505];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> b[i];

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    for(int i = 0; i < k; i++)
        s -= b[i];

    if(s != 0)
    {
        cout << "NO";
        return 0;
    }

    int d = 0;

    int x = 0;

    for(int i = 0; i < k; i++)
    {
        int y = x;
        int z = a[x];

        while(z < b[i])
        {
            y++;
            z += a[y];
        }

        if(z != b[i])
        {
            cout << "NO";
            return 0;
        }

        int Max = a[x];

        for(int j = x; j <= y; j++)
            Max = max(Max, a[j]);

        if(y == x);
        else
        if(Max > a[x])
        {
            int p = x;

            while(a[p] != Max)
                p++;

            int q = p;

            for(int j = q; j > x; j--)
                {
                    v.push_back(-(q + 1 - d));
                    d++;
                }

            int w = q + 1 - d;

            for(int j = q; j < y; j++)
                {
                    v.push_back(w);
                    d++;
                }
        }
        else
        {
            int p = x;

            while(p <= y && a[p] == Max)
                p++;

            int q = p - 1;

            if(q >= y)
            {
                cout << "NO";
                return 0;
            }

            int w = q + 1 - d;

            for(int j = q; j < y; j++)
                {
                    v.push_back(w);
                    d++;
                }

            int c = 0;

            for(int j = q; j > x; j--)
               {
                    v.push_back(c - w);
                    d++;
                    c++;
               }
        }

        x = y + 1;
    }

    cout << "YES\n";

    for(auto to:v)
    {
        cout << abs(to) << ' ';

        if(to > 0)
            cout << 'R';
        else cout << 'L';

        cout << "\n";
    }
}