#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int n, a[max_n];

int solve(int l, int r) {
    bool ok = true;
    for (int i = l; i < r; ++i) {
        ok &= a[i] <= a[i + 1];
    }
    if (ok) {
        return r - l + 1;
    }
    int mid = (l + r) / 2;
    return max(solve(l, mid), solve(mid + 1, r));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << endl;
    return 0;
}