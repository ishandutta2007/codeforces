#include <bits/stdc++.h>

using i64 = long long;

int n, m;
int scan(int r, int c) {
    std::cout << "SCAN " << r << " " << c << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

int dig(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > m) {
        return 0;
    }
    std::cout << "DIG " << r << " " << c << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

void solve() {
    std::cin >> n >> m;
    
    // x + y - 2
    int ul = scan(1, 1);
    // x - 1 + m - y
    int ur = scan(1, m);
    int sx = (ul + ur) / 2 + (3 - m);
    int sy = (ul - ur) / 2 + (1 + m);
    
    int dx = scan(sx / 2, 1) - sy + 2;
    int dy = scan(1, sy / 2) - sx + 2;
    int x1 = (sx + dx) / 2, x2 = (sx - dx) / 2;
    int y1 = (sy + dy) / 2, y2 = (sy - dy) / 2;
    if (dig(x1, y1)) {
        assert(dig(x2, y2));
    } else {
        assert(dig(x1, y2));
        assert(dig(x2, y1));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}