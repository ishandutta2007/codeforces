#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int a, b, n, m;

        cin >> a >> b >> n >> m;

        if(min(a, b) >= m && a + b >= n + m)
            cout << "Yes\n";
        else cout << "No\n";
    }
}