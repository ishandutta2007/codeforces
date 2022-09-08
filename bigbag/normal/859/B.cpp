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

const int max_n = 1, inf = 1011111111;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = inf;
    for (int x = 1; x <= n; ++x) {
        int res = x * 2 + ((n + x - 1) / x) * 2;
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}