#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, a, b, px[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < 300005; i++)
        px[i] = (px[i - 1] ^ i);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        if(px[a - 1] == b)
            cout << a << "\n";
        else
        if(px[a] == b)
            cout << a + 2 << "\n";
        else cout << a + 1 << "\n";
    }
}