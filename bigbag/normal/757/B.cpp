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

int n, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    int ans = 1;
    for (int i = 2; i < max_n; ++i) {
        int x = 0;
        for (int j = i; j < max_n; j += i) {
            x += cnt[j];
        }
        ans = max(ans, x);
    }
    printf("%d\n", ans);
    return 0;
}