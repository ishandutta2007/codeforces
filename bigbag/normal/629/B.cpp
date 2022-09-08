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

const int max_n = 5555, inf = 1111111111;

int n, l[max_n], r[max_n];
char c[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> l[i] >> r[i];
    }
    int ans = 0;
    for (int i = 1; i <= 366; ++i) {
        int x = 0, y = 0;
        for (int j = 0; j < n; ++j) {
            if (l[j] <= i && i <= r[j]) {
                if (c[j] == 'F') {
                    ++x;
                } else {
                    ++y;
                }
            }
        }
        ans = max(ans, 2 * min(x, y));
    }
    cout << ans << endl;
    return 0;
}