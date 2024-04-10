#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, n, x, a, b;

int32_t main()
{
    cin >> t;
    for(int tt=0;tt<t;tt++)
    {
        cin >> n >> x >> a >> b;
        cout << min(n-1, abs(a-b)+x) << "\n";
    }
    return 0;
}