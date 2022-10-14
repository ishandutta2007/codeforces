#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    int unread = 0, p = 0;
    vector<pair<int, int>> notifs;
    vector<int> cnt(N), time(N);
    for (int q = 0; q < Q; q++) {
        if (int t; cin >> t, t == 1) {
            int x;
            cin >> x, x--;
            unread++;
            cnt[x]++;
            notifs.emplace_back(x, q);
        } else if (t == 2) {
            int x;
            cin >> x, x--;
            unread -= cnt[x];
            cnt[x] = 0;
            time[x] = q + 1;
        } else if (t == 3) {
            int c;
            cin >> c;
            while (p < c) {
                auto [x, i] = notifs[p++];
                cnt[x] -= i >= time[x];
                unread -= i >= time[x];
            }
        } else {
            assert(false);
        }
        cout << unread << '\n';
    }
    return 0;
}