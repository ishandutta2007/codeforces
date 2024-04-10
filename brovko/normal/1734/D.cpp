#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        k--;

        queue <pair <int, int> > lf, rg;

        int p = k - 1, s = 0, mn = 0;

        while(p >= 0)
        {
            s += a[p];
            mn = min(mn, s);

            if(s > 0)
            {
                lf.push({mn, s});
                s = mn = 0;
            }

            p--;
        }

        lf.push({mn, 1e18});

        p = k + 1, s = mn = 0;

        while(p < n)
        {
            s += a[p];
            mn = min(mn, s);

            if(s > 0)
            {
//                cout << s << ' ' << mn << endl;
                rg.push({mn, s});
                s = mn = 0;
            }

            p++;
        }

//        cout << mn << endl;

        rg.push({mn, 1e18});

        int h = a[k];

        while(h >= 0 && h < 1e17)
        {
//            cout << h << endl;
            if(lf.front().f > rg.front().f)
            {
//                cout << 1 << endl;
                if(lf.front().f + h < 0)
                    h = -3e18;

                h += lf.front().s;
                lf.pop();
            }
            else
            {
//                cout << "! " << rg.front().f << endl;
                if(rg.front().f + h < 0)
                    h = -3e18;

                h += rg.front().s;
                rg.pop();
            }
//            cout << h << endl;
        }

        cout << (h > 1e17 ? "YES\n" : "NO\n");
    }
}