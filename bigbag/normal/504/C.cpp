#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1111111111;

int n, x, a[max_n], c[max_n], c1[max_n], c2[max_n];

bool palindrom() {
    memset(c, 0, sizeof(c));
    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (c[a[i]] == 0) {
            ++f;
        } else {
            --f;
        }
        c[a[i]] ^= 1;
    }
    return f <= 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (!palindrom()) {
        printf("0\n");
        return 0;
    }
    int poz = 0;
    while (poz <= n - poz - 1 && a[poz] == a[n - poz - 1]) {
        ++poz;
    }
    long long ans = 0;
    if (poz > n - poz - 1) {
        ans = n;
        printf("%I64d\n", (ans * (ans + 1)) / 2);
        return 0;
    }
    int l = poz, r = n - poz - 1;
    int mid = (l + r) / 2;
    for (int i = l; i <= r; ++i) {
        ++c1[a[i]];
    }
    int poz1 = r;
    while (poz1 > l) {
        int x = c2[a[poz1]] + 1;
        int y = c1[a[poz1]] - 1;
        if (n % 2 == 1 && poz1 == mid) {
            if ((c2[a[poz1]] + c1[a[poz1]]) % 2 == 0) {
                break;
            } else {
                --poz1;
            }
            continue;
        }
        if ((n % 2 == 1 && poz1 < mid) || (n % 2 == 0 && poz1 <= mid)) {
            if (a[poz1] == a[r - poz1]) {
                --poz1;
            } else {
                break;
            }
            continue;
        }
        if (x <= y) {
            c1[a[poz1]] = y;
            c2[a[poz1]] = x;
            --poz1;
        } else {
            break;
        }
    }
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    for (int i = l; i <= r; ++i) {
        ++c2[a[i]];
    }
    int poz2 = l;
    while (poz2 < r) {
        int x = c1[a[poz2]] + 1;
        int y = c2[a[poz2]] - 1;
        if (n % 2 == 1 && poz2 == mid) {
            if ((c2[a[poz2]] + c1[a[poz2]]) % 2 == 0) {
                break;
            } else {
                ++poz2;
            }
            continue;
        }
        if ((n % 2 == 1 && poz2 > mid) || (n % 2 == 0 && poz2 > mid)) {
            if (a[poz2] == a[r - poz2]) {
                ++poz2;
            } else {
                break;
            }
            continue;
        }
        if (x <= y) {
            c1[a[poz2]] = x;
            c2[a[poz2]] = y;
            ++poz2;
        } else {
            break;
        }
    }
    long long x = poz, y = poz1, z = poz2;
    //cout << y << " " << z << endl;
    ans = x * x + (x + 1) * (r - y + 1) + (x + 1) * (z - l + 1) - 1;
    cout << ans << endl;
    return 0;
}