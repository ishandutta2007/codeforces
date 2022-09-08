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

const int max_n = 555, inf = 1111111111;

int n;
long long sum, x, y, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    x = y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%I64d", &a[i][j]);
            if (a[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (x != i) {
            for (int j = 0; j < n; ++j) {
                sum += a[i][j];
            }
            break;
        }
    }
    long long q = 0;
    for (int i = 0; i < n; ++i) {
        q += a[x][i];
    }
    if (q >= sum) {
        printf("-1\n");
        return 0;
    }
    a[x][y] = sum - q;
    long long ans = a[x][y];
    for (int i = 0; i < n; ++i) {
        x = y = 0;
        for (int j = 0; j < n; ++j) {
            x += a[i][j];
            y += a[j][i];
        }
        if (x != sum || y != sum) {
            printf("-1\n");
            return 0;
        }
    }
    x = y = 0;
    for (int i = 0; i < n; ++i) {
        x += a[i][i];
        y += a[n - i - 1][i];
    }
    if (x != sum || y != sum) {
        printf("-1\n");
        return 0;
    }
    cout << ans << endl;
    return 0;
}