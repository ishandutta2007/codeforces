#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x[] = {500, 1000, 1500, 2000, 2500};
    int m[5];
    int w[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> m[i];
    }
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> w[i];
        ans += max(x[i] * 3 / 10, x[i] - x[i] * m[i] / 250 - 50 * w[i]);
    }
    int hs, hu;
    cin >> hs >> hu;
    ans += 100 * hs - 50 * hu;
    cout << ans << "\n";
}