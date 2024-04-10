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

const int max_n = 222222, inf = 1011111111;

int n, ans, sum, f, a[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            ++ans;
            int v = i;
            while (used[v] == 0) {
                used[v] = 1;
                v = a[v];
            }
        }
    }
    if (ans == 1) {
        --ans;
    }
    while (n--) {
        scanf("%d", &f);
        sum += f;
    }
    if (sum % 2 == 0) {
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}