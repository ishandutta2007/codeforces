#include <bits/stdc++.h>
using namespace std;

void IncModulus(int& x, int y, int modulus)
{
    x += y;
    if (x >= modulus) {
        x -= modulus;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, modulus;
    cin >> n >> m >> modulus;
    vector<int> a(n, 0);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                ++a[j];
            }
        }
    }

    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }

    vector<int> ans[2];
    int cur = 0;
    ans[cur].assign(n + 1, 0);
    ans[cur][cnt[2]] = 1;
    for (int i = m; i < n; ++i) {
        int nxt = 1 - cur;
        ans[nxt].assign(n + 1, 0);
        for (int cnt2 = 0; cnt2 <= n; ++cnt2) {
            int cnt1 = 2 * i - 2 * cnt2;
            if (cnt1 >= 0 && cnt1 + cnt2 <= n) {
                int cnt0 = n - cnt1 - cnt2;

                if (cnt0 >= 2) {
                    int t = (1LL * cnt0 * (cnt0 - 1) / 2) % modulus;
                    IncModulus(ans[nxt][cnt2], (1LL * ans[cur][cnt2] * t) % modulus, modulus);
                }
                if (cnt1 >= 2) {
                    int t = (1LL * cnt1 * (cnt1 - 1) / 2) % modulus;
                    IncModulus(ans[nxt][cnt2 + 2], (1LL * ans[cur][cnt2] * t) % modulus, modulus);
                }
                if (cnt0 >= 1 && cnt1 >= 0) {
                    int t = (1LL * cnt0 * cnt1) % modulus;
                    IncModulus(ans[nxt][cnt2 + 1], (1LL * ans[cur][cnt2] * t) % modulus, modulus);
                }
            }
        }
        swap(nxt, cur);
    }
    cout << ans[cur][n] << endl;

    return 0;
}