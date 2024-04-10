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

const int max_n = 222222, inf = 2111111111;

int n, m, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    sort(b, b + m);
    b[m] = inf;
    a[n] = inf;
    int max_r = -inf, aa, bb;
    for (int i = 0; i <= n; ++i) {
        int x = a[i];
        int l = -1, r = m;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (b[mid] >= x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        //cout << i << " " << r << endl;
        int a = (n - i) * 3 + i * 2;
        int b = (m - r) * 3 + r * 2;
        int rr = a - b;
        if (max_r < rr) {
            max_r = rr;
            aa = a;
            bb = b;
        }
    }
    cout << aa << ":" << bb << endl;
    return 0;
}