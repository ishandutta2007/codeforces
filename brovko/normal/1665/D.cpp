#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

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
        int x = 0;

        for(int i = 0; i < 29; i++)
        {
            cout << "? " << (1 << i + 1) - x << ' ' << (1 << i + 2) - x << endl;

            int y;
            cin >> y;

            if(y == (1 << i))
                x += (1 << i);
        }

        cout << "? " << (1 << 29) - x + 1 << ' ' << (1 << 29) - x + 4 << endl;

        int y;
        cin >> y;

        if(y == 1)
            x += (1 << 29);

        cout << "! " << x << endl;
    }
}