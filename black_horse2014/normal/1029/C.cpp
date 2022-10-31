#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

int l[N], r[N], maxL[N], minR[N];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int ans = 0;
    int curl = 0;
    int curr = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        maxL[i] = curl, minR[i] = curr;
        curl = max(curl, l[i]);
        curr = min(curr, r[i]);
    }
    curr = 1e9 + 7, curl = 0;
    for (int i = n; i > 0; i--) {
        int from = max(curl, maxL[i]);
        int to = min(curr, minR[i]);
        curl = max(curl, l[i]);
        curr = min(curr, r[i]);
        ans = max(ans, to - from);
    }
    cout << ans << endl;
    return 0;
}