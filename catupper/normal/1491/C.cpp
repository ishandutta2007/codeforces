#include <iostream>

using namespace std;
using Int = long long;
Int cnt[5500];
Int accum[5500];

void solve()
{
    Int n, s;
    Int ans = 0;
    cin >> n;
    fill(cnt, cnt + n, 0);
    fill(accum, accum + n, 0);
    for (int i = 0; i < n; i++) {
        if (i)
            accum[i] += accum[i - 1];
        cnt[i] += accum[i];
        cin >> s;
        s--;
        if (cnt[i] < s) {
            ans += s - cnt[i];
            cnt[i] = s;
        }
        cnt[i] -= s;
        cnt[i + 1] += cnt[i];
        accum[i + 2] += 1;
        if (i + 2 + s < 5500)
            accum[i + 2 + s] -= 1;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}