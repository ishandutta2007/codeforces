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

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] += i;
    }
    sort(a, a + n);
    a[n] = inf;
    for (int i = n - 1; i >= 0; --i) {
        a[i] -= i;
        if (a[i] < 0 || a[i] > a[i + 1]) {
            printf(":(\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}