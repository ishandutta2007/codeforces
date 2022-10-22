#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int s = 0;

        for(int i = 0; i < n - 1; i++)
            s += a[i];

        if(a[n - 1] > s || (a[n - 1] + s) % 2 != 0)
            cout << "T\n";
        else cout << "HL\n";
    }
}