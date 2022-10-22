#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, n, a[300005], lp[1000005], b[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < 1000005; i++)
        if(lp[i] == 0)
    {
        lp[i] = i;

        for(int j = i * i; j < 1000005; j += i)
            if(lp[j] == 0)
                lp[j] = i;
    }

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
        {
            b[i] = 1;

            while(a[i] > 1)
            {
                if(lp[a[i] / lp[a[i]]] == lp[a[i]])
                    a[i] /= lp[a[i]] * lp[a[i]];
                else
                {
                    b[i] *= lp[a[i]];
                    a[i] /= lp[a[i]];
                }
            }
        }

        map <int, int> m;

        for(int i = 0; i < n; i++)
            m[b[i]]++;

        int x = 0, y = 0;

        for(auto to:m)
        {
            if(to.x == 1 || to.y % 2 == 0)
                y += to.y;

            x = max(x, to.y);
        }

        y = max(x, y);

        int q;
        cin >> q;

        while(q--)
        {
            int z;
            cin >> z;

            if(z == 0)
                cout << x << "\n";
            else cout << y << "\n";
        }
    }
}