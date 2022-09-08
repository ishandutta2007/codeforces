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

int n, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    while (m--) {
        int x;
        scanf("%d", &x);
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d ", l + 1);
    }
    return 0;
}