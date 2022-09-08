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

const int max_n = 1111111, inf = 1000000007;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    int mn = inf;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, b[i]);
        ans += mn * a[i];
    }
    cout << ans << endl;
    return 0;
}