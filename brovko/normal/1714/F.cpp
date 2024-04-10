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
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, d12, d23, d13;

        cin >> n >> d12 >> d23 >> d13;

        if((d12 + d13 + d23) % 2 || d12 + d23 + d13 < 2 * max({d12, d23, d13}))
        {
            cout << "NO\n";
            continue;
        }

//        a + b = d12
//        a + c = d13
//        b + c = d23

        int a = (d12 + d13 - d23) / 2;
        int b = d12 - a;
        int c = d13 - a;

        if(a + b + c + 1 > n)
        {
            cout << "NO\n";
//            cout << a << ' ' << b << ' ' << c << "\n";
            continue;
        }

        if(c == 0)
        {
            cout << "YES\n";

//            cout << a << ' ' << b << ' ' << c << "\n";

            vector <int> v = {1};

            for(int i = 3; i <= n; i++)
            {
                if(v.size() == a)
                    v.pb(3);

                if(v.size() == d12)
                    v.pb(2);

                if(i > 3)
                    v.pb(i);

                if(v.size() == a)
                    v.pb(3);

                if(v.size() == d12)
                    v.pb(2);
            }

            for(int i = 0; i < n - 1; i++)
                cout << v[i] << ' ' << v[i + 1] << "\n";

            continue;
        }

        cout << "YES\n";

//        cout << a << ' ' << b << ' ' << c << "\n";

        int x = 1;

        vector <int> v = {1};

        for(int i = 0; i < d12 - 1; i++)
        {
            cout << x << ' ' << i + 4 << "\n";
            x = i + 4;

            v.pb(x);
        }

        cout << x << ' ' << 2 << "\n";
        x = d12 + 3;

        v.pb(2);

        int y = v[a];

        for(int i = 0; i < c - 1; i++)
        {
            cout << y << ' ' << x << "\n";
            y = x;
            x = d12 + i + 4;
        }

        cout << y << ' ' << 3 << "\n";

        for(int i = a + b + c + 2; i <= n; i++)
            cout << i << ' ' << 1 << "\n";
    }
}

/*
1
7 2 3 5

*/