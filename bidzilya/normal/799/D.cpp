#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LIM = 1e5;

int a, b, h, w, n;
vector<int> ar;
vector<int> dp[2];

int GetMul(int a, int b) {
    long long result = 1LL * a * b;
    if (result >= LIM) {
        result = LIM;
    }
    return result;
}

void Update(int a, int b, int c) {
    dp[a][b] = max(dp[a][b], c);
}

bool IsEnough(int h, int w) {
    return (h >= a && w >= b) || (h >= b && w >= a);
}

void Solve() {
    if (IsEnough(h, w)) {
        cout << 0 << endl;
        return;
    }
    sort(ar.begin(), ar.end());
    int cur = 0;
    dp[cur].assign(LIM + 1, 0);
    dp[cur][h] = w;
    for (int count = 1; count <= n; ++count) {
        int value = ar[n - count];
        int nxt = 1 - cur;
        dp[nxt].assign(LIM + 1, 0);
        for (int i = 0; i <= LIM; ++i) {
            Update(nxt, GetMul(i, value), dp[cur][i]);
            Update(nxt, i, GetMul(dp[cur][i], value));
        }
        cur = nxt;
        for (int i = 0; i <= LIM; ++i) {
            if (IsEnough(i, dp[cur][i])) {
                cout << count << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

bool Read() {
    if (!(cin >> a >> b >> h >> w >> n)) {
        return false;
    }
    ar.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}