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

const int max_n = 500055, inf = 1000111222;
const long double eps = 1e-10;

int q, n, a[max_n];
long long sum[max_n];

long double get(int pos, int mx) {
    long double res = (sum[pos] + mx);
    return res / pos;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &q);
    n = 2;
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d", &a[n]);
            sum[n] = a[n];
            if (n) {
                sum[n] += sum[n - 1];
            }
            ++n;
        } else {
            int l = 1, r = n - 2;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (get(mid, a[n - 1]) > eps + get(mid + 1, a[n - 1])) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            printf("%.10f\n", (double) (a[n - 1] - get(r, a[n - 1])));
        }
    }
    return 0;
}