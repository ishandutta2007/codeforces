#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, k, x[105], y[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        int f = 0;

        for(int i = 0; i < n; i++)
        {
            int F = 1;

            for(int j = 0; j < n; j++)
                if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
                    F = 0;

            if(F)
                f = 1;
        }

        if(f)
            cout << "1\n";
        else cout << "-1\n";
    }
}