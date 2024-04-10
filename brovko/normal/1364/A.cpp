#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, x, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> x;

        int L = -1;
        int R = -1;
        int s = 0;

        for(int i = 0; i < n; i++)
            {
                cin >> a[i];

                if(L == -1 && a[i] % x != 0)
                    L = i;

                if(a[i] % x != 0)
                    R = i;

                s += a[i];
            }

        if(R == -1)
            cout << -1;
        else if(s % x)
            cout << n;
        else cout << max(n - L - 1, R);

        cout << "\n";
    }
}