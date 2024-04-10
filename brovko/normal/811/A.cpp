#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    int x = 1;

    while(true)
    {
        if(a < x)
        {
            cout << "Vladik";
            return 0;
        }
        a -= x;

        x++;

        if(b < x)
        {
            cout << "Valera";
            return 0;
        }
        b -= x;

        x++;
    }
}