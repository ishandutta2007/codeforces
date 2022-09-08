#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
int b[max_n];

bool check(int cnt) {
    memset(b, -1, sizeof(b));
    int pos = 0;
    for (int i = n - cnt - 1; i < n; ++i) {
        b[pos] = a[i];
        pos += 2;
    }
    pos = 1;
    for (int i = 0; i < cnt; ++i) {
        b[pos] = a[i];
        pos += 2;
    }
    pos = 0;
    for (int i = cnt; i < n - cnt - 1; ++i) {
        while (b[pos] != -1) {
            ++pos;
        }
        b[pos] = a[i];
    }
    int res = 0;
    for (int i = 1; i + 1 < n; ++i) {
        res += (b[i] < b[i - 1]) && (b[i] < b[i + 1]);
    }
    return res >= cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mx = (n - 1) / 2;
    int l = 0, r = mx + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    check(l);
    cout << l << "\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
    return 0;
}