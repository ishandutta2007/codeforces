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

const int max_n = 100011, inf = 1000111222;

long long x, a[max_n], ans;
int n, tp;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%I64d%d", &x, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        long long cnt = (x / a[i]) * a[i];
        if (ans < cnt) {
            ans = cnt;
            tp = i;
        }
    }
    printf("%d %I64d\n", tp + 1, ans / a[tp]);
    return 0;
}