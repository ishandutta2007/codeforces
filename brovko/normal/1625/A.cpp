#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, l, x[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> l;

        for(int i = 0; i < n; i++)
            cin >> x[i];

        int ans = 0;

        for(int i = 0; i < l; i++)
        {
            int k = 0;

            for(int j = 0; j < n; j++)
                if(x[j] & (1 << i))
                    k++;

            if(k * 2 >= n)
                ans += (1 << i);
        }

        cout << ans << "\n";
    }
}