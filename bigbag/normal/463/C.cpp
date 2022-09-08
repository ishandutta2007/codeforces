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

const int max_n = 2222, max_lev = 13, inf = 1111111111;

int n, a[max_n][max_n], num1[max_n][max_n], num2[max_n][max_n];
long long sum1[2 * max_n], sum2[2 * max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            num1[i][j] = i + j - 1;
            num2[i][j] = j - i + n;
            sum1[num1[i][j]] += a[i][j];
            sum2[num2[i][j]] += a[i][j];
        }
    }
    long long ans1 = -1, ans2 = -1, x1, y1, x2, y2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i + j) % 2) {
                if (ans1 < sum1[num1[i][j]] + sum2[num2[i][j]] - a[i][j]) {
                    ans1 = sum1[num1[i][j]] + sum2[num2[i][j]] - a[i][j];
                    x1 = i;
                    y1 = j;
                }
            } else {
                if (ans2 < sum1[num1[i][j]] + sum2[num2[i][j]] - a[i][j]) {
                    ans2 = sum1[num1[i][j]] + sum2[num2[i][j]] - a[i][j];
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout << ans1 + ans2 << endl << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}