#include <bits/stdc++.h>
using namespace std;

int cnt[2][1<<20];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n; cin >> n;
    int s = 0;
    cnt[0][s]++;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        s ^= x;
        cnt[i&1][s]++;
    }
    long long ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1<<20; j++) {
            ans += 1LL * cnt[i][j] * (cnt[i][j] - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}