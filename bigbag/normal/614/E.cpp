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

const int max_n = 33, inf = 1111111111;

int n, a[max_n], sum, b[max_n];

int ok() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] % 2) {
            ++cnt;
        }
    }
    if (cnt > 1) {
        return -1;
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] % 2) {
            return i;
        }
    }
    return n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        b[i] = a[i];
    }
    /*if (n == 1) {
        printf("%d\n", a[0]);
        for (int i = 0; i < a[0]; ++i) {
            printf("a");
        }
        printf("\n");
        return 0;
    }*/
    if (ok() == -1) {
        printf("0\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a[i]; ++j) {
                printf("%c", i + 'a');
            }
        }
        printf("\n");
        return 0;
    }
    int ans = 1;
    for (int dd = 2; dd <= sum; ++dd) {
        int d = dd;
        if (d % 2 == 0) {
            d /= 2;
        }
        if (sum % d == 0) {
            int f = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] % d) {
                    f = 1;
                    break;
                }
                b[i] = a[i] / d;
            }
            if (f == 0) {
                if ((ok() == n) || (ok() != -1 && dd % 2)) {
                    ans = max(ans, dd);
                }
            }
        }
    }
    printf("%d\n", ans);
    if (ans % 2 == 0) {
        ans /= 2;
    }
    for (int i = 0; i < n; ++i) {
        a[i] /= ans;
        b[i] = a[i];
    }
    int poz = ok();
    while (ans--) {
        for (int i = 0; i < n; ++i) {
            if (i == poz) {
                continue;
            }
            for (int j = 0; j < a[i] / 2; ++j) {
                printf("%c", 'a' + i);
            }
        }
        for (int j = 0; j < a[poz]; ++j) {
            printf("%c", 'a' + poz);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == poz) {
                continue;
            }
            for (int j = 0; j < a[i] / 2; ++j) {
                printf("%c", 'a' + i);
            }
        }
    }
    printf("\n");
    return 0;
}