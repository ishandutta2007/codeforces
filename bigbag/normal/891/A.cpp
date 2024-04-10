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

const int max_n = 2222, inf = 1011111111;

int n, a[max_n], ones;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ++ones;
        }
    }
    if (ones) {
        cout << n - ones << endl;
        return 0;
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        int g = a[i], cnt = -1;
        for (int j = i; j < n; ++j) {
            ++cnt;
            g = __gcd(g, a[j]);
            if (g == 1) {
                ans = min(ans, cnt);
                break;
            }
        }
    }
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << n - 1 + ans << endl;
    }
    return 0;
}