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

    int n, k;
    cin >> n >> k;

    int s = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            cout << (j & -j) * (j & -j) * 2 << ' ';
            s += (j & -j) * (j & -j) * 2;
        }

        cout << endl;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << (i & -i) * (i & -i) << ' ';
            s += (i & -i) * (i & -i);
        }

        cout << endl;
    }

//    cout << s;

    int x = 0;

    while(k--)
    {
        int y;
        cin >> y;

        x ^= y;
        y = x;

        int i = 0;

        for(int c = 4; c >= 0; c--)
            if(x & (1 << 2 * c))
            {
                i += (1 << c);

                if(c)
                    x ^= (1 << 2 * c - 2);
            }

        int j = 0;

        for(int c = 4; c >= 0; c--)
            if(x & (1 << 2 * c + 1))
            {
                j += (1 << c);

                if(c)
                    x ^= (1 << 2 * c - 1);
            }

        cout << i + 1 << ' ' << j + 1 << endl;

        x = y;
    }
}