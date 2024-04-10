#include <map>
#include <set>
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

const int max_n = 111, inf = 111111111;

int n, c, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] >= c) {
            ans = max(ans, a[i] - c - a[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}