#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2222222, inf = 1000000007;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % inf, b / 2);
    }
    return (1LL * a* power(a, b - 1)) % inf;
}

int n, ans, f[max_n], rf[max_n];

int get_c(int n, int k) {
    return (1LL * ((1LL * f[n] * rf[k]) % inf) * rf[n - k]) % inf;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % inf;
    }
    for (int i = 0; i < max_n; ++i) {
        rf[i] = power(f[i], inf - 2);
    }
    for (int i = 0; i <= n; ++i) {
        ans += get_c(i + n + 1, i + 1);
        ans %= inf;
    }
    cout << ans << endl;
    return 0;
}