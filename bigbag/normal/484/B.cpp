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

const int max_n = 3111111, inf = 1111111111;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 1; i <= 3000000; ++i) {
        if (a[0] >= i) {
            b[i] = -1;
        } else {
            int l = 0, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (a[mid] < i) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            b[i] = a[l];
        }
        //if (i <= 10) cout << i << " " << b[i] << endl;
    }
    for (int i = 0; i < n;) {
        for (int j = 1; a[i] * j < a[n - 1]; ++j) {
            if (b[a[i] * (j + 1)] > a[i] * j) ans = max(ans, b[a[i] * (j + 1)] - a[i] * j);
        }
        int poz = i;
        while (poz < n && a[poz] == a[i]) {
            ++poz;
        }
        i = poz;
    }
    cout << ans << endl;
    return 0;
}