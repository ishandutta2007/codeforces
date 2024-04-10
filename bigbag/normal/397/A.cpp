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

const int max_n = 111, inf = 111111111;

int n, used[max_n], l[max_n], r[max_n], a[max_n];

bool good(int x, int y) {
    for (int i = 1; i < n; ++i) {
        if (l[i] < y && l[i] >= x || l[i] < x && r[i] > x) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    int ans = 0;
    for (int i = l[0]; i <= r[0]; ++i) {
        int x = i + 1;
        for (int j = i + 1; good(i, j) && j <= r[0]; ++j) {
            x = j + 1;
        }
        //cout << i << ' ' << x << endl;
        ans += x - i - 1;
        i = x - 1;
    }
    cout << ans << endl;
    return 0;
}