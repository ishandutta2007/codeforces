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

        vector <int> b(n);

        for(int i = 0; i < n; i++)
            cin >> b[i];

        vector <int> a;

        vector <int> v;

        for(int i = 0; i < n; i++)
        {
            if(b[i] == n + 1 || b[i] == 0)
                v.pb(i);
        }

        vector <int> pos[n + 2];

        for(int i = 0; i < n; i++)
            pos[b[i]].pb(i);

        int p = (b[v[0]] == 0);
        int k = 0;

        while(true)
        {
            p ^= 1;

            if(p)
                for(auto x:v)
                    k = max(k, x + 1);

            int last = -1;

            for(auto x:v)
            {
                if(pos[x + 1].empty())
                    a.pb(x + 1);
                else last = x;
            }

            if(last != -1)
            {
                a.pb(last + 1);
                v = pos[last + 1];
            }
            else break;
        }

        cout << k << "\n";

        for(auto x:a)
            cout << x << ' ';

        cout << "\n";
    }
}