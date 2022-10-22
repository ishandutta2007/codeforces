#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int L = 0, R = n * 2000;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << M << endl;

        int x;
        cin >> x;

        if(x == 1)
            R = M;
        else L = M;
    }

    int S1 = R;
    int ans = S1;

    for(int i = 2; i <= n; i++)
    {
        int x = (S1 - 1) / i * i;

        if(x >= S1 - i + 1)
        {
            cout << "? " << x / i << endl;

            int y;
            cin >> y;

            if(i == y)
                ans = min(ans, x);
        }
    }

    cout << "! " << ans;
}