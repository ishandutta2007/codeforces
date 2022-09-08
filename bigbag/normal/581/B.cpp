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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int mx = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > mx) {
            ans[i] = 0;
        } else {
            ans[i] = mx - a[i] + 1;
        }
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}