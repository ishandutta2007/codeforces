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

const int max_n = 202222, inf = 1011111111;

int n, a[max_n], f[3], tp[max_n];

int get(int x) {
    if (x <= 1899) {
        return 2;
    }
    return 1;
}

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        if (get(x) != tp[i]) {
            return false;
        }
        x += a[i];
    }
    return true;
}

void wa() {
    printf("Impossible\n");
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &tp[i]);
        ++f[tp[i]];
    }
    if (f[1] == n) {
        printf("Infinity\n");
        return 0;
    }
    if (f[2] == n) {
        int bal = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            bal += a[i];
            if (i + 1 < n) {
                mx = max(mx, bal);
            }
        }
        printf("%d\n", 1899 - mx + bal);
        return 0;
    }
    int l, r, sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (tp[i] != tp[i + 1]) {
            if (tp[i] == 2) {
                if (a[i] <= 0) {
                    wa();
                }
                l = 1900 - a[i];
                r = 1899;
                break;
            } else {
                if (a[i] >= 0) {
                    wa();
                }
                l = 1900;
                r = 1899 - a[i];
                break;
            }
        }
        sum += a[i];
    }
    l -= sum;
    r -= sum;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    for (int i = r; i >= l; --i) {
        if (check(i)) {
            printf("%d\n", i + sum);
            return 0;
        }
    }
    wa();
    return 0;
}