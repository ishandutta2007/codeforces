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

const int max_n = 111;

int n, m, ans[max_n], a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        for (int j = a[i]; j <= n; ++j) {
            if (!ans[j]) {
                ans[j] = a[i];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}