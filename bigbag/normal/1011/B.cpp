#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, m, a[max_n];

bool check(int x) {
    int cnt = 0;
    for (int i = 0; i < max_n; ++i) {
        cnt += a[i] / x;
    }
    return cnt >= n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }
    int l = 0, r = 111;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}