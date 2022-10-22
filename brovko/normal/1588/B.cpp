#include <bits/stdc++.h>
#define int long long
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

        int L = 1, R = n + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            cout << "? 1 " << M << endl;

            int z;
            cin >> z;

            if(z == 0)
                L = M;
            else R = M;
        }

        int x, y;

        cout << "? " << L << ' ' << n << endl;
        cin >> x;

        cout << "? " << R << ' ' << n << endl;
        cin >> y;

        int d = x - y;
        int j = R + d;

        int x2, y2;

        cout << "? " << j << ' ' << n << endl;
        cin >> x2;

        cout << "? " << j + 1 << ' ' << n << endl;
        cin >> y2;

        int d2 = x2 - y2;
        int k = j + d2;

        cout << "! " << L << ' ' << j << ' ' << k << endl;
    }
}