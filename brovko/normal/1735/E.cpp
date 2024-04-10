#include <bits/stdc++.h>
//#define int long long
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
        int n;
        cin >> n;

        vector <int> d1(n), d2(n);

        for(int i = 0; i < n; i++)
            cin >> d1[i];

        for(int i = 0; i < n; i++)
            cin >> d2[i];

        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());

        bool F = 1;

        for(int i = 0; i < n; i++)
            F &= (d1[i] + d2[n - 1 - i] == d1[0] + d2[n - 1]);

        if(F)
        {
            cout << "YES\n";

            for(int i = 0; i < n; i++)
                cout << d1[i] << ' ';

            cout << "\n";

            cout << 0 << ' ' << d1[0] + d2[n - 1] << "\n";
            continue;
        }

        vector <int> Ds;

        for(int i = 0; i < n; i++)
            Ds.pb(abs(d1[n - 1] - d2[i]));

        for(int i = 0; i < n; i++)
            Ds.pb(abs(d2[n - 1] - d1[i]));

        bool f = 0;

        for(auto D:Ds)
        {
            vector <int> u1(n), u2(n);

            int x = n - 1, y = n - 1, nx = n - 1, ny = n - 1;

            bool F = 1;

            while(x >= 0 || y >= 0)
            {
                if(y < 0 || x >= 0 && d1[x] > d2[y])
                {
                    if(d1[x] <= D)
                        break;

                    u1[x] = 1;

                    while(ny >= 0 && (u2[ny] || d2[ny] > d1[x] - D))
                        ny--;

                    if(ny < 0 || d2[ny] != d1[x] - D)
                    {
                        F = 0;
                        break;
                    }
                    else u2[ny] = 1;
                }
                else
                {
                    if(d2[y] <= D)
                        break;

                    u2[y] = 2;

                    while(nx >= 0 && (u1[nx] || d1[nx] > d2[y] - D))
                        nx--;

                    if(nx < 0 || d1[nx] != d2[y] - D)
                    {
                        F = 0;
                        break;
                    }
                    else u1[nx] = 2;
                }

                while(x >= 0 && u1[x])
                    x--;

                while(y >= 0 && u2[y])
                    y--;
            }

            if(!F)
                continue;

            vector <int> r1, r2;

            for(int j = 0; j < n; j++)
                if(u1[j] == 0)
                    r1.pb(d1[j]);

            for(int j = 0; j < n; j++)
                if(u2[j] == 0)
                    r2.pb(d2[j]);

            reverse(r2.begin(), r2.end());

//            for(auto x:r1)
//                cout << x << ' ';
//
//            cout << endl;
//
//            for(auto x:r2)
//                cout << x << ' ';
//
//            cout << endl;

            assert(r1.size() == r2.size());

            for(int j = 0; j < r1.size(); j++)
                F &= (r1[j] + r2[j] == D);

            if(F && !f)
            {
                f = 1;
                cout << "YES\n";

                int mn = 0;

                for(int j = 0; j < n; j++)
                    if(u1[j] == 2)
                        mn = min(mn, -d1[j]);

                mn = -mn;

                for(int j = 0; j < n; j++)
                    if(u1[j] == 2)
                        cout << mn - d1[j] << ' ';
                    else cout << mn + d1[j] << ' ';

                cout << "\n";

                cout << mn << ' ' << mn + D << "\n";
            }
        }

        if(!f)
            cout << "NO\n";
    }
}

/*
1
2
10 33
26 69

*/