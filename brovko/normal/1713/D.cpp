#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
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
        int k;
        cin >> k;

        int n = (1 << k);

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            a[i] = i + 1;

        while(n > 1)
        {
            if(n == 2)
            {
                cout << "? " << a[0] << ' ' << a[1] << endl;

                int x;
                cin >> x;

                cout << "! " << (x == 1 ? a[0] : a[1]) << endl;

                n /= 2;
            }
            else
            {
                vector <int> b;

                for(int i = 0; i < n; i += 4)
                {
                    cout << "? " << a[i] << ' ' << a[i + 2] << endl;

                    int x;
                    cin >> x;

                    int X, Y;

                    if(x == 0)
                    {
                        X = a[i + 1];
                        Y = a[i + 3];
                    }
                    else if(x == 1)
                    {
                        X = a[i];
                        Y = a[i + 3];
                    }
                    else
                    {
                        X = a[i + 1];
                        Y = a[i + 2];
                    }

                    cout << "? " << X << ' ' << Y << endl;

                    cin >> x;

                    if(x == 1)
                        b.pb(X);
                    else b.pb(Y);
                }

                a = b;

                n /= 4;

                if(n == 1)
                    cout << "! " << a[0] << endl;
            }
        }
    }
}