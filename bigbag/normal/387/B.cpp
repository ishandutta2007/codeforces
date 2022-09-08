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

const int max_n = 3333, inf = 111111111;

int n, m, a[max_n], b[max_n], f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (b[i] >= a[j] && f[j] == 0) {
                f[j] = 1;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}