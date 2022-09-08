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

const int max_n = 555555, inf = 1111111111;

int n, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i - 1] == a[i]) {
            continue;
        }
        if (a[i] == a[i + 1]) {
            continue;
        }
        int r = i;
        while (r + 1 < n && a[r] != a[r + 1]) {
            ++r;
        }
        --r;
        ans = max(ans, (r - i + 2) / 2);
        if ((r - i + 1) % 2) {
            for (int j = i; j <= r; ++j) {
                a[j] = a[i - 1];
            }
            i = r;
        } else {
            for (int j = i; j <= i + (r - i) / 2; ++j) {
                a[j] = a[i - 1];
            }
            for (int j = i + (r - i) / 2 + 1; j <= r; ++j) {
                a[j] = a[r + 1];
            }
            i = r;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}