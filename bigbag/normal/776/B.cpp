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

const int max_n = 111111, inf = 1011111111;

int n, a[max_n];
int ans[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    ++n;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0) {
            a[i] = 1;
            ans[1] = 1;
            for (int j = 2 * i; j <= n; j += i) {
                if (a[j] == 0) {
                    a[j] = 2;
                    ans[2] = 1;
                }
            }
        }
    }
    printf("%d\n", ans[1] + ans[2]);
    for (int i = 2; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}