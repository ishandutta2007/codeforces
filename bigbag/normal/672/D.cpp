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

int n, k, a[max_n];
long long sum;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    int poz1 = inf, poz2 = -1;
    long long res = 0, res1, res2;
    for (int i = n - 1; i > 0; --i) {
        if (a[i - 1] != a[i]) {
            res += 1LL * (n - i) * (a[i] - a[i - 1]);
            if (res > k) {
                poz2 = i;
                res -= 1LL * (n - i) * (a[i] - a[i - 1]);
                res2 = k - res;
                break;
            }
        }
    }
    res = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] != a[i]) {
            res += 1LL * (i + 1) * (a[i + 1] - a[i]);
            if (res >= k) {
                poz1 = i;
                res -= 1LL * (i + 1) * (a[i + 1] - a[i]);
                res1 = k - res;
                break;
            }
        }
    }
    if (poz1 >= poz2) {
        if (sum % n) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }
    int mx = a[poz2] - res2 / (n - poz2);
    int mn = a[poz1] + res1 / (poz1 + 1);
    if (mn > mx || (mn == mx && sum % n)) {
        if (sum % n) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }
    printf("%d\n", mx - mn);
    return 0;
}