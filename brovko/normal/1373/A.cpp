#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;

        if(a < c)
            cout << 1;
        else cout << -1;

        cout << ' ';

        if(a * b > c)
            cout << b;
        else cout << -1;

        cout << "\n";
    }
}