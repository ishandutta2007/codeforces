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

const int max_n = 1000011;

long long n, p[max_n], dp[max_n];
long long xp;

long long fun(int l, int r) {
    if (l > r) {
        return 0;
    }
    return dp[r] ^ dp[l - 1];
}

int solve() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res ^= p[i];
        for (int j = 1; j <= n; ++j) {
            res ^= (i % j);
        }
    }
    return res;
}
int solve2() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res ^= p[i];
    }
    //cout << "!" << res << endl;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] ^ i;
    }
    for (int i = 2; i <= n; ++i) {
        int o = n % i;
        int poz = (n / (2 * i)) * 2 * i;
        if (poz + i <= n) {
            //cout << i << " - " << o + 1 << " " << i - 1 << endl;
            res ^= fun(o + 1, i - 1);
        } else if (poz != n) {
            //cout << i << " - " << 1 << " " << o << endl;
            res ^= fun(1, o);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //while (true) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i]);
        }
        //cout << solve() << endl << solve2() << endl;
        cout << solve2() << endl;
    //}
    return 0;
}