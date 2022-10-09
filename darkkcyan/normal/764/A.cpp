#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, z; cin >> n >> m >> z;
    int ans = 0;
    for (int i = 1; i * n <= z; ++i)
        ans += (i * n % m) == 0;
    cout << ans;
    return 0;
}