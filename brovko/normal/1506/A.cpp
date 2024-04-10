#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, m, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> x;

        int a = (x - 1) / n, b = (x - 1) % n;

        cout << b * m + a + 1 << "\n";
    }
}