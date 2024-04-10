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

const int max_n = 111, inf = 1111111111;

int n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    --x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int d = 0; d < n; ++d) {
        int cnt = 0, q = 0;
        if (x - d >= 0) {
            ++cnt;
            q += a[x - d];
        }
        if (x + d < n && d) {
            ++cnt;
            q += a[x + d];
        }
        ans += (cnt == q) * cnt;
    }
    cout << ans << endl;
    return 0;
}