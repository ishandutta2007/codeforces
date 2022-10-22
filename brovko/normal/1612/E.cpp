#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const ld eps = 1e-9;

int n, m[200005], k[200005];
vector <int> v[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> m[i] >> k[i];
        v[m[i]].pb(i);
    }

    ld ans = 0;

    for(int c = 1; c <= 20; c++)
    {
        vector <ld> u;

        for(int i = 0; i <= 200000; i++)
        {
            ld ans2 = 0;

            for(auto x:v[i])
            {
                if(k[x] >= c)
                    ans2++;
                else ans2 += (ld)k[x] / c;
            }

            if(ans2 > 0)
                u.pb(ans2);
        }

        sort(u.rbegin(), u.rend());

        ld ans3 = 0;

        for(int i = 0; i < min(c, (int)u.size()); i++)
            ans3 += u[i];

        ans = max(ans, ans3);
    }

    vector <pair <ld, int> > u2;

    for(int i = 0; i <= 200000; i++)
    {
        ld ans2 = 0;

        for(auto x:v[i])
        {
            ans2 += (ld)k[x];
        }

        if(ans2 > 0)
            u2.pb({ans2, i});
    }

    sort(u2.rbegin(), u2.rend());

    ld ans3 = 0;

    for(int i = 0; i < u2.size(); i++)
    {
        ans3 += u2[i].x;

        if(i >= 20)
            ans = max(ans, ans3 / (i + 1));
    }



    for(int c = 1; c <= 20; c++)
    {
        vector <pair <ld, int> > u;

        for(int i = 0; i <= 200000; i++)
        {
            ld ans2 = 0;

            for(auto x:v[i])
            {
                if(k[x] >= c)
                    ans2++;
                else ans2 += (ld)k[x] / c;
            }

            if(ans2 > 0)
                u.pb({ans2, i});
        }

        sort(u.rbegin(), u.rend());

        ld ans3 = 0;

        for(int i = 0; i < min(c, (int)u.size()); i++)
            ans3 += u[i].x;

        if(abs(ans - ans3) < eps)
        {
            cout << c << "\n";

            for(int i = 0; i < c; i++)
                cout << u[i].y << ' ';

            return 0;
        }
    }

    ans3 = 0;

    for(int i = 0; i < u2.size(); i++)
    {
        ans3 += u2[i].x;

        if(i >= 20 && abs(ans - ans3 / (i + 1)) < eps)
        {
            cout << i + 1 << "\n";

            for(int j = 0; j <= i; j++)
                cout << u2[j].y << ' ';

            return 0;
        }
    }

    assert(0);
}