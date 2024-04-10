#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    for(int i=0; i<1000000; i++)
    {
        int x = a / b;
        if(x == c && i > 0)
        {
            cout << i;
            return 0;
        }

        a = a % b * 10;
    }

    cout << -1;
}