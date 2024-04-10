#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int k = (n + 3) / 4;

        for(int i = 0; i < n - k; i++)
            cout << 9;

        for(int i = 0; i < k; i++)
            cout << 8;

        cout << "\n";
    }
}