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

const int max_n = 1111111, inf = 1111111111;

int n, m, a[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        ++a[i % 5];
    }
    for (int i = 1; i <= n; ++i) {
        int o = (5 - i % 5) % 5;
        ans += a[o];
    }
    cout << ans << endl;
    return 0;
}