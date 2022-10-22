#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, m, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;

        if(k == n * m - 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
}