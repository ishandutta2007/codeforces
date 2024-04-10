#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, W;
    cin >> N >> W;
    vector<int> cnt;
    int B = 1;
    while (B <= W)
        B <<= 1, cnt.push_back(0);

    for (int i = 0, w, k; i < N; i++) {
        cin >> w, k = 0;
        while (w > 1)
            w >>= 1, k++;
        cnt[k]++;
    }

    multiset<int, greater<int>> bins;
    bins.insert(W);

    int M = cnt.size() - 1;
    for (int i = M; i >= 0; i--) {
        int w = 1 << i;
        while (cnt[i]-- > 0) {
            int space = *bins.begin();
            if (space >= w) {
                bins.erase(bins.find(space));
                bins.insert(space - w);
            } else {
                bins.insert(W - w);
            }
        }
    }
    return bins.size();
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}