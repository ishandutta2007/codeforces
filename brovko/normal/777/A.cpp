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
    n %= 6;
    x++;

    for(int i = n; i > 0; i--)
    {
        if(i % 2 == 0)
        {
            if(x == 2)
                x = 3;
            else if(x == 3)
                x = 2;
        }
        else
        {
            if(x == 1)
                x = 2;
            else if(x == 2)
                x = 1;
        }
    }

    cout << x - 1;
}