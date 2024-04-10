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

const int max_n = 111111, inf = 1111111111;

int n, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    a[n + 1] = inf;
    cin >> m;
    while (m--) {
        int l = 0, r = n, x;
        cin >> x;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l + 1 << endl;
    }
    return 0;
}