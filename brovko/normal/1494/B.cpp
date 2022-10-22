#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, u, d, r, l;

int f(int x)
{
    if(x >= 0 && x <= n - 2)
        return 1;

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> u >> r >> d >> l;

        int fl = 0;

        for(int i = 0; i < 16; i++)
        {
            if(f(u - i % 2 - i / 2 % 2) && f(r - i / 2 % 2 - i / 4 % 2) && f(d - i / 4 % 2 - i / 8 % 2) && f(l - i / 8 % 2 - i % 2))
                fl = 1;
        }

        if(fl)
            cout << "YES\n";
        else cout << "NO\n";
    }
}