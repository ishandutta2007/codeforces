#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int x, y, z, a, b, c; cin >> x >> y >> z >> a >> b >> c;
    auto solve = [&]() {
        if (a < x) return 0;
        a -= x;
        if (y > a + b) return 0;
        if (z <= a + b + c - y) return 1;
        return 0;
    };
    puts(solve() ? "YES" : "NO");
    return 0;
}