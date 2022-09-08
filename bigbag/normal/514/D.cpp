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

const int max_n = 111111, max_lev = 19, inf = 1111111111;

int n, m, k, ans[11], a[max_n][11], maxs[5][max_lev][max_n], num[max_n];

void get_all_maxs(int poz) {
    for (int i = 0; i < n; ++i) {
        maxs[poz][0][i] = a[i][poz];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            maxs[poz][i][j] = max(maxs[poz][i - 1][j], maxs[poz][i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_max(int poz, int l, int r) {
    if (l > r) {
        return -inf;
    }
    int lev = num[r - l + 1];
    return max(maxs[poz][lev][l], maxs[poz][lev][r - (1 << lev) + 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        get_all_maxs(i);
    }
    int mx = 0, poz;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
        if (sum <= k) {
            int l = i, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                int sum = 0;
                for (int j = 0; j < m; ++j) {
                    sum += get_max(j, i, mid);
                }
                if (sum <= k) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            //cout << i << " - " << l << endl;
            if (l - i + 1 > mx) {
                mx = l - i + 1;
                for (int j = 0; j < m; ++j) {
                    ans[j] = get_max(j, i, l);
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}