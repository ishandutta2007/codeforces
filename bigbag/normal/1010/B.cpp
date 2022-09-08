#include <bits/stdc++.h>

using namespace std;

const int max_n = 33, inf = 1000111222;

int m, n, a[max_n];

int query(int x) {
    cout << x << endl;
    cout.flush();
    int res;
    cin >> res;
    if (res == 0) {
        exit(0);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        int res = query(1);
        a[i] = res;
    }
    int cur = 0;
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int res = query(mid) * a[cur];
        ++cur;
        cur %= n;
        if (res == -1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return 0;
}