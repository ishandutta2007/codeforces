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

const int max_n = 11, inf = 1111111111;

int n, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        ++a[x];
    }
    long long ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            ans += 1LL * a[i] * a[j];
        }
    }
    cout << ans << endl;
    return 0;
}