#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

set <int> q;

int nxt(int x)
{
    auto y = q.upper_bound(x);

    if(y == q.end())
        return -1;

    return (*y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);
        vector <int> b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        q.clear();

        for(int i = 0; i < n; i++)
            q.insert(a[i]);

        vector <int> v[n + 1];

        for(int i = 0; i < n; i++)
            v[a[i]].pb(i);

        while(!q.empty())
        {
            b[v[*q.rbegin()].back()] = (*q.begin());
//
//            cout << (*q.rbegin()) << ' ' << (*q.begin()) << endl;
//            cout << v[(*q.rbegin())].back() << ' ' << v[*q.begin()].back() + 1 << endl;

            int x = (*q.begin());

            while(x != (*q.rbegin()))
            {
                int y = nxt(x);

//                cout << x << ' ' << y << ' ' << v[x].back() + 1 << ' ' << v[y].back() + 1 << endl;

                b[v[x].back()] = y;
                v[x].pop_back();

                if(v[x].empty())
                    q.erase(x);

                x = y;
            }

            v[x].pop_back();

            if(v[x].empty())
                q.erase(x);
        }

        for(int i = 0; i < n; i++)
            cout << b[i] << ' ';

        cout << "\n";
    }
}