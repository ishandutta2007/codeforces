#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0, sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        long long y = min(sum, x / 2);
        ans += y;
        sum -= y;
        x -= 2 * y;
        ans += x / 3;
        sum += x % 3;
    }
    cout << ans << endl;
    return 0;
}