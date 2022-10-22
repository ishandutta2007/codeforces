#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int f(int x)
{
    int y = x;

    while(x)
    {
        if(x % 10 != 0 && y % (x % 10) != 0)
            return 0;

        x /= 10;
    }

    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        while(f(n) == 0)
            n++;

        cout << n << "\n";
    }
}