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

int n, k, a[max_n];//, f[max_n];
long long sum;

/*void update(int i, int x) {
    for (; i < n; i = (i | (i + 1))) {
        f[i] += x;
    }
}

void update(int l, int r, int x) {
    update(l, x);
    if (r + 1 < n) {
        update(r + 1, -x);
    }
}

int get(int r) {
    int res = a[r];
    for (; r >= 0; --r) {
        res += f[r];
    }
    return res;
}

int get_max() {
    int l = 0, r = a[n - 1];
    while (r - l > 1) {
        int mid = (l + r) / 2;

    }
}*/

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
        //cout << i << " " << res << endl;
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
        //cout << i << " " << res << endl;
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
    //printf("%d\n", get_max() - get_min());
    return 0;
}