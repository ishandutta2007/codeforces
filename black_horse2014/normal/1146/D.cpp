#include <bits/stdc++.h>
using namespace std;

int seen[1100000];

long long solve(int n, int a, int b) {
    for (int i = 0; i < a; i++) seen[i] = -1;
    int x = 0, y = 0;
    long long ret = 0;
    for (int i = 0; i < a + b; i++) {
        if (x >= b) x -= b;
        else x += a;
        int z = x % a;
        if (seen[z] == -1) {
            seen[z] = y;
            if (y <= n) {
                long long j = (n - z) / a;
                long long k = (y - z) / a;
                ret += (n + 1 - y) * (k + 1) + (j - k) * (n + 1 - z) - (j + 1 + k) * (j - k) / 2 * a;
            }
        }
        y = max(y, x);
    }
    return ret;
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    cout << solve(n, a, b);
    return 0;
}