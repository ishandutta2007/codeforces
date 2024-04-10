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

const int max_n = 1111, inf = 1111111111;

int n, k, d, cnt, num[max_n], ans[max_n][max_n];

void rec(int poz) {
    if (cnt == n) {
        return;
    }
    if (poz == d) {
        for (int i = 0; i < d; ++i) {
            ans[i][cnt] = num[i];
        }
        ++cnt;
        return;
    }
    for (int i = 1; i <= k; ++i) {
        if (cnt == n) {
            return;
        }
        num[poz] = i;
        rec(poz + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &d);
    rec(0);
    if (cnt < n) {
        printf("-1\n");
    } else {
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}