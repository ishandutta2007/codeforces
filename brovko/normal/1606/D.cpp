#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int r = 0, b = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i][0] > a[r][0])
                r = i;

            if(a[i][0] < a[b][0])
                b = i;
        }

        int x = 0;

        while(a[r][x] > a[b][x])
            x++;

        int L1[n], R1[n], L2[n], R2[n];

        for(int i = 0; i < n; i++)
        {
            L1[i] = 1e9;
            R1[i] = -1e9;
            L2[i] = 1e9;
            R2[i] = -1e9;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < x; j++)
            {
                L1[i] = min(L1[i], a[i][j]);
                R1[i] = max(R1[i], a[i][j]);
            }

        for(int i = 0; i < n; i++)
            for(int j = x; j < m; j++)
            {
                L2[i] = min(L2[i], a[i][j]);
                R2[i] = max(R2[i], a[i][j]);
            }

        vector <pair <int, int> > v;
        int c[n] = {0};

        for(int i = 0; i < n; i++)
            v.pb({L1[i], i});

        sort(v.rbegin(), v.rend());

        set <int> L1R, R1B, L2B, R2R;
        map <int, int> l1r, r1b, l2b, r2r;

        for(int i = 0; i < n; i++)
        {
            R1B.insert(R1[i]);
            L2B.insert(L2[i]);
            r1b[R1[i]]++;
            l2b[L2[i]]++;
        }

        int F = 0;

        if(x == 0 || x == m)
        {
            cout << "NO\n";
            continue;
        }

//        cout << x << endl;
//
//        for(int i = 0; i < n; i++)
//            cout << L1[i] << ' ' << R1[i] << ' ' << L2[i] << ' ' << R2[i] << endl;

        for(int i = 0; i < n - 1; i++)
        {
            int j = v[i].y;
            c[j] = 1;

            L1R.insert(L1[j]);
            R2R.insert(R2[j]);
            l1r[L1[j]]++;
            r2r[R2[j]]++;

            r1b[R1[j]]--;
            l2b[L2[j]]--;

            if(r1b[R1[j]] == 0)
                R1B.erase(R1[j]);

            if(l2b[L2[j]] == 0)
                L2B.erase(L2[j]);

            if(F == 0 && (*L1R.begin()) > (*R1B.rbegin()) && (*L2B.begin()) > (*R2R.rbegin()))
            {
                F = 1;
                cout << "YES\n";

                for(int z = 0; z < n; z++)
                {
                    if(c[z])
                        cout << "R";
                    else cout << "B";
                }

                cout << ' ' << x << "\n";
            }
        }

        if(F == 0)
            cout << "NO\n";
    }
}