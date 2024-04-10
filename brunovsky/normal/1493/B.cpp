#include <bits/stdc++.h>

using namespace std;

// *****

bool rev(int n, int N) {
    static const int map[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
    int a = n / 10, b = n % 10;
    return map[a] >= 0 && map[b] >= 0 && 10 * map[b] + map[a] < N;
}

auto solve() {
    int H, M, h, m;
    scanf("%d%d\n%d:%d", &H, &M, &h, &m);
    while (true) {
        if (rev(h, M) && rev(m, H)) {
            printf("%02d:%02d\n", h, m);
            break;
        }
        m = (m + 1) % M;
        h = (h + (m == 0)) % H;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    scanf("%u", &T);
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}