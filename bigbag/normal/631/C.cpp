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

const int max_n = 222222, inf = 1111111111;

int n, m, a[max_n], mx[max_n], tp[max_n], x[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ans[i] = inf;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &tp[i], &x[i]);
    }
    mx[m] = -1;
    for (int i = m - 1; i >= 0; --i) {
        mx[i] = max(x[i], mx[i + 1]);
    }
    int l, r, last = -1, len, ppp;
    for (int i = 0; i < m; ++i) {
        if (x[i] > mx[i + 1]) {
            if (last == -1) {
                last = tp[i];
                sort(a, a + x[i]);
                if (tp[i] == 2) {
                    reverse(a, a + x[i]);
                }
                l = 0;
                r = x[i] - 1;
                len = x[i];
                ppp = r;
            } else {
                if (last != tp[i]) {
                    for (int j = 0; j < len - x[i]; ++j) {
                        ans[ppp] = a[r];
                        --ppp;
                        if (l < r) {
                            --r;
                        } else {
                            ++r;
                        }
                    }
                    swap(l, r);
                    last = tp[i];
                    len = x[i];
                }
            }
        }
    }
    //cout << l << " " << r << endl;
    while (ppp >= 0) {
        ans[ppp] = a[r];
        --ppp;
        if (l < r) {
            --r;
        } else {
            ++r;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == inf) {
            ans[i] = a[i];
        }
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}