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

const int max_n = 5055, mod = 998244353;

int a[5];
long long sum[5];

int c[max_n][max_n], f[max_n];

void get_all() {
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
    }
    for (int i = 0; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all();
    cin >> a[0] >> a[1] >> a[2];
    a[3] = a[0];
    int ans = 1;
    for (int i = 0; i < 3; ++i) {
        for (int x = 0; x <= a[i]; ++x) {
            int pl = (1LL * c[a[i]][x] * c[a[i + 1]][x]) % mod;
            pl = (1LL * pl * f[x]) % mod;
            sum[i] += pl;
        }
        //cout << i << " " << sum[i] << endl;
        sum[i] %= mod;
        ans = (1LL * ans * sum[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}