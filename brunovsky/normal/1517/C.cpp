#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> p(N + 1), where(N + 1);
    vector<vector<int>> seen(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        where[p[i]] = i;
        seen[i][i] = p[i];
    }

    for (int n = 1; n <= N; n++) {
        int k = where[n];
        for (int i = n, j = 1; i < k; i++, j++) {
            seen[i + 1][j] = seen[i][j];
        }
        for (int i = N, j = N - n + 1; i > k; i--, j--) {
            seen[i][j - 1] = seen[i][j];
        }
        for (int i = n + 1; i <= N; i++) {
            where[seen[i][i - n]] = i;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << (j > 1 ? " " : "") << seen[i][j];
        }
        cout << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}