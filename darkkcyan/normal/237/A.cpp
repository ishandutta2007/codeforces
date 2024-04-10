#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prev_h, prev_m;
    cin >> prev_h >> prev_m;
    int cnt = 1, ans = 1;
    for (int i = 1; i < n; ++i) {
        int h, m; cin >> h >> m;
        if (h == prev_h and m == prev_m) ++cnt;
        else {
            ans = max(ans, cnt);
            cnt = 1;
            prev_h = h;
            prev_m = m;
        }
    }
    ans = max(ans, cnt);
    cout << ans;
    return 0;
}