#include <unordered_map>
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

const int max_n = 1000111, inf = 1111111111;

int n, k, x, a[max_n], b[max_n], c[max_n];
unordered_map<int, int> q;
long long ans;

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

long long fun() {
    long long res = 0;
    c[0] = 0;
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] ^ a[i - 1];
    }
    q.clear();
    for (int i = n; i >= 0; --i) {
        if (q.count(x ^ c[i])) res += q[x ^ c[i]];
        ++q[c[i]];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    int c = 0;
    for (int i = 29; i >= 0; --i) {
        if (get_bit(k, i)) {
            ++c;
        }
    }
    if (c < 15) {
        int mask = 0;
        ans = (1LL * n * (n + 1)) / 2;
        for (int i = 29; i >= 0; --i) {
            mask += (1 << i);
            if (get_bit(k, i)) {
                for (int j = 0; j < n; ++j) {
                    a[j] = (b[j] & mask);
                }
                ans -= fun();
                x += 1 << i;
            }
        }
    } else {
        --k;
        int mask = 0;
        for (int i = 30; i >= 0; --i) {
            mask += (1 << i);
            if (get_bit(k, i) == 0) {
                x += 1 << i;
                for (int j = 0; j < n; ++j) {
                    a[j] = (b[j] & mask);
                }
                ans += fun();
                x -= 1 << i;
            } else {
                x += 1 << i;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}