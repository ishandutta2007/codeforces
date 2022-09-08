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

const int max_n = 111111, inf = 1000000007;

int n, k, a[max_n], b[max_n], ans = 1;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n / k; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n / k; ++i) {
        scanf("%d", &b[i]);
    }
    int pw = power(10, k, inf);
    --pw;
    int pw2 = power(10, k - 1, inf);
    --pw2;
    for (int i = 0; i < n / k; ++i) {
        int x = (pw / a[i] + 1) % inf;
        int y = (b[i] * power(10, k - 1, a[i])) % a[i];
        y = (a[i] - y) % a[i];
        if (pw2 >= y) {
            y = (pw2 - y);
            y = y / a[i] + 1;
        } else {
            y = 0;
        }
        x -= y;
        ans = (1LL * ans * x) % inf;
    }
    cout << ans << endl;
    return 0;
}