#include <bits/stdc++.h>
using namespace std;

const int kInf = 1e9;
const int kMaxH = 1e3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> w(n), h(n);
    int min_h = 1;
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
        min_h = max(min_h, min(w[i], h[i]));
    }

    int ans = kInf;
    for (int cur_h = min_h; cur_h <= kMaxH; ++cur_h) {
        int cur_w = 0;
        int used = 0;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            if (w[i] <= cur_h && h[i] <= cur_h) {
                cur_w += w[i];
                if (w[i] > h[i]) {
                    a.push_back(w[i] - h[i]);
                }
            } else if (w[i] <= cur_h) {
                ++used;
                cur_w += h[i];
            } else {
                cur_w += w[i];
            }
        }
        if (used * 2 <= n) {
            sort(a.begin(), a.end());
            for (int i = (int) a.size() - 1; i >= 0; --i) {
                if ((used + 1) * 2 <= n) {
                    cur_w -= a[i];
                    ++used;
                }
            }
            ans = min(ans, cur_w * cur_h);
        }
    }

    cout << ans << endl;

    return 0;
}