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
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = inf;
    for (int i = 1; i + 1 < n; ++i) {
        int mx = a[i + 1] - a[i - 1];
        for (int j = 0; j + 1 < i; ++j) {
            mx = max(mx, a[j + 1] - a[j]);
        }
        for (int j = i + 1; j + 1 < n; ++j) {
            mx = max(mx, a[j + 1] - a[j]);
        }
        ans = min(ans, mx);
    }
    cout << ans << endl;
    return 0;
}