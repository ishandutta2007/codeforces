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

int n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int mn = inf;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] - mn) % k) {
            printf("-1\n");
            return 0;
        }
        ans += (a[i] - mn) / k;
    }
    cout << ans << endl;
    return 0;
}