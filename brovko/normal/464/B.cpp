#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a[8][3];

void rec(int d)
{
    if(d == 8)
    {
        vector <long long> v;

        for(int i = 0; i < 8; i++)
            for(int j = 0; j < i; j++)
            {
                long long x = 0;

                for(int z = 0; z < 3; z++)
                    x += (a[i][z] - a[j][z]) * 1ll * (a[i][z] - a[j][z]);

                v.pb(x);
            }

        long long y = 1e18;

        for(int i = 0; i < 28; i++)
            y = min(y, v[i]);

        int ky = 0, k2y = 0, k3y = 0;

        for(int i = 0; i < 28; i++)
        {
            if(v[i] == y)
                ky++;

            if(v[i] == 2 * y)
                k2y++;

            if(v[i] == 3 * y)
                k3y++;
        }

        if(y > 0 && ky == 12 && k2y == 12 && k3y == 4)
        {
            cout << "YES\n";

            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 3; j++)
                    cout << a[i][j] << ' ';

                cout << "\n";
            }

            exit(0);
        }

        return;
    }

    rec(d + 1);

    swap(a[d][0], a[d][1]);
    rec(d + 1);

    swap(a[d][1], a[d][2]);
    rec(d + 1);

    swap(a[d][0], a[d][1]);
    rec(d + 1);

    swap(a[d][1], a[d][2]);
    rec(d + 1);

    swap(a[d][0], a[d][1]);
    rec(d + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];

    rec(0);

    cout << "NO";
}