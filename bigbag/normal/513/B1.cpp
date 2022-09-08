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

const int max_n = 9, inf = 1111111111;

int n, m, a[max_n];

int sum() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int mn = a[i];
        res += mn;
        for (int j = i + 1; j < n; ++j) {
            mn = min(mn, a[j]);
            res += mn;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    int mx = 0;
    do {
        mx = max(mx, sum());
    } while (next_permutation(a, a + n));
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    int cnt = 0;
    do {
        if (mx == sum()) {
            ++cnt;
            if (cnt == m) {
                for (int i = 0; i < n; ++i) {
                    cout << a[i] << " ";
                }
                return 0;
            }
        }
    } while (next_permutation(a, a + n));
    return 0;
}