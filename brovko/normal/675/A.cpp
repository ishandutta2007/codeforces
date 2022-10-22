#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    if(c == 0)
    {
        if(a == b)
            cout << "YES";
        else cout << "NO";

        return 0;
    }

    if((b - a) % c == 0 && (b - a) / c >= 0)
        cout << "YES";
    else cout << "NO";
}