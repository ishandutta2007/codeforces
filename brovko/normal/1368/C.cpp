#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << 8 + 7 * n << "\n";
    cout << "0 0\n";

    int x = 0;

    for(int i = 0; i < n + 1; i++)
    {
        for(int a = 0; a < 3; a++)
            for(int b = 0; b < 3; b++)
        {
            if(a == 0 && b == 0 || a == 1 && b == 1);
                else cout << x + a << ' ' << x + b << "\n";
        }

        x += 2;
    }
}