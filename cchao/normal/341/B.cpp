#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, t, g[100010];
int main() {
    scanf("%d", &n);
    memset(g, 0x7f, sizeof g);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        int k = lower_bound(g+1, g+n, t) - g;
        ans = max(ans, k);
        g[k] = t;
    }
    printf("%d\n", ans);
    return 0;
}