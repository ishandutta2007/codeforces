#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[30];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1)
    {
        cout << a[0] << "\n";

        for(int i = 0; i < a[0]; i++)
            cout << 'a';

        return 0;
    }

    int k = 0, x = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2)
        {
            k++;
            x = i;
        }
    }

    if(k > 1)
    {
        cout << 0 << "\n";

        for(int i = 0; i < n; i++)
            for(int j = 0; j < a[i]; j++)
                cout << (char)(i + 'a');

        return 0;
    }

//    if(k == 1)
//    {
//        cout << 1 << "\n";
//
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < a[i] / 2; j++)
//                cout << (char)(i + 'a');
//
//        cout << (char)(x + 'a');
//
//        for(int i = n - 1; i >= 0; i--)
//            for(int j = 0; j < a[i] / 2; j++)
//                cout << (char)(i + 'a');
//
//        return 0;
//    }

    int g = 0;

    for(int i = 0; i < n; i++)
        g = gcd(g, a[i]);

    cout << g << "\n";

    if(g % 2)
    {
        for(int i = 0; i < g; i++)
        {
            for(int z = 0; z < n; z++)
                for(int j = 0; j < a[z] / g / 2; j++)
                    cout << (char)('a' + z);

            cout << (char)('a' + x);

            for(int z = n - 1; z >= 0; z--)
                for(int j = 0; j < a[z] / g / 2; j++)
                    cout << (char)('a' + z);
        }

        return 0;
    }

    for(int i = 0; i < g / 2; i++)
    {
        for(int z = 0; z < n; z++)
            for(int j = 0; j < a[z] / g; j++)
                cout << (char)(z + 'a');

        for(int z = n - 1; z >= 0; z--)
            for(int j = 0; j < a[z] / g; j++)
                cout << (char)(z + 'a');
    }
}