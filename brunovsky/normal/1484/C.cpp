#include <bits/stdc++.h>

using namespace std;

// *****

default_random_engine mt(random_device{}());
using intd = uniform_int_distribution<int>;

int different(int u, int v1, int v2) {
    assert(v1 <= v2 && (v1 != u || v2 != u));
    if (v1 == v2)
        return v1;
    intd dist(v1, v2 - 1);
    int v = dist(mt);
    return v + (v >= u);
}

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> days(M);
    vector<int> cnt(N + 1, 0), which(M, -1);
    int half = (M + 1) / 2;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        days[i].resize(k);
        for (int& f : days[i])
            cin >> f;
        which[i] = intd(0, k - 1)(mt);
        cnt[days[i][which[i]]]++;
    }
    int x = max_element(begin(cnt), end(cnt)) - begin(cnt);
    if (cnt[x] > half) {
        for (int i = 0; i < M; i++) {
            int k = days[i].size();
            if (days[i][which[i]] == x && k > 1) {
                which[i] = different(which[i], 0, k - 1);
                cnt[x]--;
                if (cnt[x] == half)
                    break;
            }
        }
    }
    if (cnt[x] <= half) {
        cout << "YES" << endl;
        for (int i = 0; i < M; i++)
            cout << days[i][which[i]] << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}