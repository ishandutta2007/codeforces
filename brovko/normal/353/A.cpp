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

    int n;
    cin >> n;

    vector <int> x(n), y(n);

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int sx = 0, sy = 0;
    bool F = 0;

    for(int i = 0; i < n; i++)
    {
        sx += x[i];
        sy += y[i];

        if(x[i] % 2 + y[i] % 2 == 1)
            F = 1;
    }

    if((sx + sy) % 2 || !F && sx % 2)
        cout << -1;
    else if(sx % 2 == 0)
        cout << 0;
    else cout << 1;
}