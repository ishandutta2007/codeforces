#include <bits/stdc++.h>
using namespace std;

int a[210000];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int ans = 1, cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1 || a[i] > a[i - 1] * 2) {
            ans = max(ans, cur);
            cur = 0;
        }
        cur++;
    }
    ans = max(ans, cur);
    cout << ans << endl;
    return 0;
}