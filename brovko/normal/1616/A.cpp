#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 150;

int t, n, a[105], k[305];

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

        for(int i = 0; i < 305; i++)
            k[i] = 0;

        for(int i = 0; i < n; i++)
        {
            if(k[N + a[i]] == 0)
                k[N + a[i]]++;
            else k[N - a[i]]++;
        }

        int ans = 0;

        for(int i = 0; i < 305; i++)
            ans += bool(k[i]);

        cout << ans << "\n";
    }
}