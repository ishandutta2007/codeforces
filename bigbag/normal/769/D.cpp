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

const int max_n = 10111, inf = 1011111111;

int n, k, cnt[max_n];
long long ans;

bool get_bit(int mask, int pos) {
    return (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    if (k == 0) {
        for (int i = 0; i < max_n; ++i) {
            ans += 1LL * cnt[i] * (cnt[i] - 1);
        }
    } else {
        for (int i = 0; i < (1 << 14); ++i) {
            int x = 0;
            for (int j = 0; j < 14; ++j) {
                x += get_bit(i, j);
            }
            if (x == k) {
                for (int j = 0; j < max_n; ++j) {
                    if ((i ^ j) < max_n) {
                        ans += 1LL * cnt[j] * cnt[i ^ j];
                    }
                }
            }
        }
    }
    printf("%I64d\n", ans / 2);
    return 0;
}