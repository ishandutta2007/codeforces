#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    if(n == 2 && x == 0)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    if(n % 4 == 2 && x == 0)
    {
        n -= 2;
        x = 1;
        cout << "500000 500001 ";
    }

    int k = n % 4;

    if(k == 1)
        cout << x;
    else if(k == 2)
        cout << 0 << ' ' << x;
    else if(k == 3)
        cout << "500000 500001 " << (x ^ 1);
    else
    {
        if(x != 1)
            cout << "500000 500001 1 " << x;
        else cout << "1 2 8 10";
    }

    cout << ' ';
    if(k == 0)
        k = 4;

    n -= k;

    int y = 1e6 - 1;

    while(n)
    {
        cout << y << ' ';
        n--;
        y--;
    }
}