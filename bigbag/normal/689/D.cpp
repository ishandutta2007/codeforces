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
const int max_lev = 20;

int num[max_n];
int maxs[max_lev][max_n];
int mins[max_lev][max_n];

void get_all_maxs(int n, int a[], int b[]) {
    for (int i = 0; i < n; ++i) {
        maxs[0][i] = a[i];
        mins[0][i] = b[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            maxs[i][j] = max(maxs[i - 1][j], maxs[i - 1][j + (1 << (i - 1))]);
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_max(int l, int r) {
    int lev = num[r - l + 1];
    return max(maxs[lev][l], maxs[lev][r - (1 << lev) + 1]);
}

int get_min(int l, int r) {
    int lev = num[r - l + 1];
    return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
}

int n, a[max_n], b[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    get_all_maxs(n, a, b);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= b[i]) {
            int l = i, r = n;
            if (a[i] == b[i]) {
                l = i - 1;
            } else {
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (get_max(i, mid) < get_min(i, mid)) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
            }
            //cout << i << " " << l << endl;
            if (l + 1 < n && get_max(i, l + 1) == get_min(i, l + 1)) {
                int L = l + 1;
                l = L;
                r = n;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (get_max(i, mid) == get_min(i, mid)) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                ans += l - L + 1;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}