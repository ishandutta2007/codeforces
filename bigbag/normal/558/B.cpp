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

const int max_n = 1000111, inf = 1111111111;

int n, l, r, len = inf, ans, a[max_n];
vector<int> poz[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        poz[a[i]].push_back(i);
    }
    for (int i = 0; i < max_n; ++i) {
        ans = max(ans, (int) poz[i].size());
    }
    for (int i = 0; i < max_n; ++i) {
        if (ans == poz[i].size()) {
            int x = poz[i].back() - poz[i][0];
            if (x < len || (len == x && poz[i][0] < l)) {
                len = x;
                l = poz[i][0];
                r = poz[i].back();
            }
        }
    }
    printf("%d %d\n", l + 1, r + 1);
    return 0;
}