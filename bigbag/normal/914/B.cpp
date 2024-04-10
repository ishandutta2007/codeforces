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

const int max_n = 101111, inf = 1011111111;

int n, a[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int f = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (f || dp[i + 1] == 0) {
            dp[i] = 1;
        }
        bool last = false;
        if (i == 0 || (i > 0 && a[i] > a[i - 1])) {
            last = true;
        }
        if (last) {
            f |= dp[i];
        }
    }
    if (dp[0]) {
        printf("Conan\n");
    } else {
        printf("Agasa\n");
    }
    return 0;
}