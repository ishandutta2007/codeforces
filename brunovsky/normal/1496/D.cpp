#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> P(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    const int L = 0, R = 1, D = 0, U = 1;
    vector<int> dist[2][2]; // dist[right?][up?]
    dist[0][0].assign(N + 2, 0), dist[0][1].assign(N + 2, 0);
    dist[1][0].assign(N + 2, 0), dist[1][1].assign(N + 2, 0);

    for (int i = 1; i <= N; i++) {
        if (P[i - 1] < P[i]) {
            dist[L][D][i] = dist[L][D][i - 1] + 1;
            dist[L][U][i] = 1;
        } else {
            dist[L][D][i] = 1;
            dist[L][U][i] = dist[L][U][i - 1] + 1;
        }
    }
    for (int i = N; i >= 1; i--) {
        if (P[i] > P[i + 1]) {
            dist[R][D][i] = dist[R][D][i + 1] + 1;
            dist[R][U][i] = 1;
        } else {
            dist[R][D][i] = 1;
            dist[R][U][i] = dist[R][U][i + 1] + 1;
        }
    }

    vector<int> longest;
    for (int i = 1; i <= N; i++) {
        longest.push_back(dist[L][U][i]);
        longest.push_back(dist[R][U][i]);
    }
    nth_element(begin(longest), begin(longest) + 2, end(longest), greater<int>{});

    int ans = 0;
    for (int x = 1; x <= N; x++) {
        int l = dist[L][D][x], r = dist[R][D][x];
        // block on the left or right immediately
        if (x == 1 || x == N || l == 1 || r == 1 || l != r)
            continue;
        // can always ascend
        if (l % 2 == 0)
            continue;
        // play far away because playing nearby does not work
        if (longest[0] > max(l, r) || longest[2] >= max(l, r))
            continue;
        ans++; // can't beat it
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}