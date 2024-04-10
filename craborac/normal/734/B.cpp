#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    long long ans = 0, a = min(k2, min(k5, k6));
    ans = a * 256;
    ans += min(k3, k2 - a) * 32;
    cout << ans << endl;
    return 0;
}