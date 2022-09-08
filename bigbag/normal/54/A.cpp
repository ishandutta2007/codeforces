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

const int max_n = 444, inf = 111111111;

int n, k, c, f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> c;
    for (int i = 0; i < c; ++i) {
        int x;
        cin >> x;
        f[x] = 1;
    }
    int ans = 0, now_day = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 1) {
            now_day = i;
            ++ans;
        }
        if (i == now_day + k) {
            ++ans;
            now_day = i;
        }
    }
    cout << ans << endl;
    return 0;
}