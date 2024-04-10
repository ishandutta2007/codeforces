#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << "? " << 1 << ' ' << n << endl;
    int x;
    cin >> x;
    
    int y = -1;
    
    if(x > 1)
    {
        cout << "? " << 1 << ' ' << x << endl;
        cin >> y;
    }
    

    if(y == x)
    {
        int L = 0, R = x - 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            cout << "? " << M + 1 << ' ' << n << endl;
            int y;
            cin >> y;

            if(y == x)
                L = M;
            else R = M;
        }

        cout << "! " << R << endl;
    }
    else
    {
        int L = x - 1, R = n - 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            cout << "? " << 1 << ' ' << M + 1 << endl;
            int y;
            cin >> y;

            if(y == x)
                R = M;
            else L = M;
        }

        cout << "! " << R + 1 << endl;
    }
}