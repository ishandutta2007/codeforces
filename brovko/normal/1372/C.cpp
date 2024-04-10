#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        a[0] = 0;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int ans = 0;
        int f = 0;

        for(int i = 0; i < n; i++)
            {
                if(a[i] > a[i + 1])
                    f = 1;

                if(a[i] == i && a[i + 1] != i + 1)
                    ans++;
            }

        if(f == 0)
            cout << "0\n";

        else if(ans == 1)
            cout << "1\n";

        else cout << "2\n";
    }
}