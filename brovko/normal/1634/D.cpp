#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int a = 1, b = 2, c = 3;

        cout << "? 1 2 3" << endl;

        int d;
        cin >> d;

        for(int i = 4; i <= n; i++)
        {
            cout << "? " << a << ' ' << b << ' ' << i << endl;

            int d1;
            cin >> d1;

            cout << "? " << a << ' ' << c << ' ' << i << endl;

            int d2;
            cin >> d2;

            int D = max({d, d1, d2});

            if(D == d1)
                c = i;
            else if(D == d2)
                b = i;

            d = D;
        }

        int mex = 1;

        while(a == mex || b == mex || c == mex)
            mex++;

        cout << "? " << a << ' ' << b << ' ' << mex << endl;

        int d1;
        cin >> d1;

        cout << "? " << c << ' ' << b << ' ' << mex << endl;

        int d2;
        cin >> d2;

        cout << "? " << a << ' ' << c << ' ' << mex << endl;

        int d3;
        cin >> d3;

        int D = max({d1, d2, d3});

        if(D == d1)
            cout << "! " << a << ' ' << b << endl;

        else if(D == d2)
            cout << "! " << c << ' ' << b << endl;

        else cout << "! " << a << ' ' << c << endl;
    }
}