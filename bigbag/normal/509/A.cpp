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

int n, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        a[i][1] = a[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}