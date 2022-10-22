#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005];

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
            cin >> a[i] >> b[i];

        int L = 0, R = n + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int x = 0;

            for(int i = 0; i < n; i++)
                if(a[i] >= M - 1 - x && b[i] >= x)
                    x++;

            if(x >= M)
                L = M;
            else R = M;
        }

        cout << L << "\n";
    }
}