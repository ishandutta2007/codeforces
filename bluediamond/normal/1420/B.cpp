#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> f(60, 0);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            f[log2(x)]++;
        }
        ll sol = 0;
        for (int i = 0; i <= 30; i++)
        {
            for (int j = i + 1; j <= 30; j++)
            {
                sol += (ll) f[i] * f[j];
            }
        }
        sol = (ll) n * (n - 1) / 2 - sol;
        cout << sol << "\n";
    }
}