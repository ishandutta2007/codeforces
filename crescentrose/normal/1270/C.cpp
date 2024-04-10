#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
const int S = 50;
int n, m, k;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        long long all = 0, all1 = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            all += x;
            all1 ^= x;
        }
        if (all == 2 * all1) {
            printf("0\n\n");
            continue;
        }
        printf("2\n");
        printf("%lld %lld\n", all1, (all + all1));

    }
}