#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ans;

long long get(int x) {
    if (n < x) {
        return 0;
    }
    return (n - x) / m + 1 - (x == 0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i * i + j * j) % m == 0) {
                ans += 1LL * get(i) * get(j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}