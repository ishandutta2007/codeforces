#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[55], used[55];

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                used[a[i] - a[j]] = 1;

        int ans = 0;

        for(int i = 0; i < 55; i++)
            if(used[i] == 1)
                ans++;

        cout << ans << "\n";

        for(int i = 0; i < 55; i++)
            used[i] = 0;
    }
}