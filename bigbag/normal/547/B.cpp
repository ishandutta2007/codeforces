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

const int max_n = 222222, max_lev = 20, inf = 1111111111;

int n, a[max_n], ans[max_n], num[max_n], mins[max_lev][max_n];

void get_all_mins() {
    for (int i = 0; i < n; ++i) {
        mins[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_min(int l, int r) {
    if (l > r) {
        return inf;
    }
    int lev = num[r - l + 1];
    return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    get_all_mins();
    for (int i = 0; i < n; ++i) {
        int l = -1, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get_min(mid, i) == a[i]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        int poz1 = r;
        l = i, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get_min(i, mid) == a[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int poz2 = l;
        ans[poz2 - poz1 + 1] = max(ans[poz2 - poz1 + 1], a[i]);
    }
    int A = 0;
    for (int i = n; i >= 1; --i) {
        A = max(A, ans[i]);
        ans[i] = A;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}