#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, s, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s >> n;

        vector <int> v;

        v.pb(s);

        while(v.size() < n)
        {
            int f = 0;

            for(int i = 0; i < v.size(); i++)
            {
                int x = 1;

                while(v[i] % (x * 10) == 0)
                    x *= 10;

                if(x != v[i] && f == 0)
                {
                    f = 1;
                    v[i] -= x;
                    v.pb(x);
                }
            }

            if(f == 0)
            {
                sort(v.begin(), v.end());

                int y = 0;

                while(v[y] == 1)
                    y++;

                int x = v[y] / 10;

                v[y] -= x;
                v.pb(x);
            }
        }

        for(auto to:v)
            cout << to << ' ';

        cout << "\n";
    }
}