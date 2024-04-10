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

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int poz = i;
        while (i + 1 < n && a[i] <= a[i + 1]) {
            ++i;
        }
        ans = max(ans, i - poz + 1);
    }
    printf("%d\n", ans);
    return 0;
}