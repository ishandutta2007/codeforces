#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, a[2025];

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

        int f = 1;

        for(int i = 0; i < n; i++)
            if(i % 2 == a[i] % 2)
                f = 0;

        if(f == 0)
        {
            cout << "-1\n";
            continue;
        }

        vector <int> v;

        while(n > 1)
        {
            int pos = 0;

            for(int i = 0; i < n; i++)
                if(a[i] == n)
                    pos = i;

            v.pb(pos + 1);
            reverse(a, a + pos + 1);


            for(int i = 0; i < n; i++)
                if(a[i] == n - 1)
                    pos = i;

            v.pb(pos);
            reverse(a, a + pos);

            v.pb(n);
            reverse(a, a + n);

            for(int i = 0; i < n; i++)
                if(a[i] == n)
                    pos = i;

            v.pb(pos + 1);
            reverse(a, a + pos + 1);

            v.pb(n);
            reverse(a, a + n);

            n -= 2;
        }

        cout << v.size() << "\n";

        for(auto to:v)
            cout << to << ' ';

        cout << "\n";
    }
}