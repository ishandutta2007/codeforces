#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
int ans = inf;

void update(int delta, int cnt) {
    int x = a[1];
    for (int i = 2; i < n; ++i) {
        x += delta;
        if (abs(a[i] - x) > 1) {
            return;
        }
        if (abs(a[i] - x) == 1) {
            ++cnt;
        }
    }
    ans = min(ans, cnt);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int x = -1; x <= 1; ++x) {
        a[0] += x;
        for (int y = -1; y <= 1; ++y) {
            a[1] += y;
            update(a[1] - a[0], (x != 0) + (y != 0));
            a[1] -= y;
        }
        a[0] -= x;
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}