#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int f[2];
ll sol;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    /// freopen ("input", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sol += x / 2;
        if (x % 2)
        {
            f[i % 2]++;
        }
    }
    sol += min(f[0], f[1]);
    cout << sol << "\n";
}