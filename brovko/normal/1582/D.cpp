#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(n % 2 == 0)
        {
            for(int i = 0; i < n; i += 2)
                cout << a[i + 1] << ' ' << -a[i] << ' ';

            cout << "\n";
            continue;
        }

        map <int, int> cnt;
        int x = 1e9;

        for(int i = 0; i < n; i++)
        {
            cnt[a[i]]++;

            if(cnt[a[i]] == 3 && abs(a[i]) >= 2)
                x = a[i];
        }

        if(x < 1e8)
        {
            int x1, x2, x3;
            int kx = 0;

            for(int i = 0; i < n; i++)
            {
                if(a[i] == x)
                {
                    kx++;

                    if(kx == 1)
                        x1 = i;

                    if(kx == 2)
                        x2 = i;

                    if(kx == 3)
                        x3 = i;
                }
            }

            for(int i = 0; i < n; i++)
            {
                if(i == x1 || i == x2)
                    b[i] = 1;
                else if(i == x3)
                    b[i] = -2;
                else
                {
                    int y = i + 1;

                    while(y == x1 || y == x2 || y == x3)
                        y++;

                    b[i] = a[y];
                    b[y] = -a[i];
                    i = y;
                }
            }

            b[x1] = 1;
            b[x2] = 1;
            b[x3] = -2;

            for(int i = 0; i < n; i++)
                cout << b[i] << ' ';

            cout << "\n";

            continue;
        }

        int s = 0;

        for(int i = 1; i < n; i++)
            s += a[i];

        x = 0;

        while(s == 0)
        {
            s += a[x] - a[x + 1];
            x++;
        }

        for(int i = 0; i < n; i++)
        {
            if(i == x)
                cout << s << ' ';
            else cout << -a[x] << ' ';
        }

        cout << "\n";
    }
}