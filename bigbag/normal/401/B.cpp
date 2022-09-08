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

const int max_n = 4444, inf = 111111111;

int k, n, t[max_n], x[max_n], y[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> x[i];
        if (t[i] == 1) {
            cin >> y[i];
        }
        used[x[i]] = 1;
        used[y[i]] = 1;
    }
    int min1 = 0, max1 = 0;
    for (int i = 1; i < k; ++i) {
        if (used[i] == 0) {
            ++max1;
        }
    }
    for (int i = 1; i < k; ++i) {
        if (used[i] == 0) {
            ++min1;
            if (used[i + 1] == 0) {
                ++i;
            }
        }
    }
    cout << min1 << ' ' << max1 << endl;
    return 0;
}