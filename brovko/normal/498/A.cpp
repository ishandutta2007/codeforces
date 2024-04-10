#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int X1, Y1, X2, Y2, n;

int sgn(int x)
{
    if(x == 0)
        return 0;

    return abs(x) / x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X1 >> Y1 >> X2 >> Y2 >> n;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(sgn(a * X1 + b * Y1 + c) != sgn(a * X2 + b * Y2 + c))
            ans++;
    }

    cout << ans;
}