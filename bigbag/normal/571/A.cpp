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

const int max_n = 1111111;

long long a[3], b[3], x, ans, sum[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

void proc() {
    long long y = x;
    y -= (a[2] - a[0]);
    y -= (a[2] - a[1]);
    if (y >= 0) {
        ans += y / 3 + 1;
    }
}

long long solve(long long d1, long long d2, long long y) {
    long long q = min(d1, y - d2), res = 0;
    int poz = 0;
    if (q >= 0) {
        res += (d2 + 1) * (q + 1);
        poz = q + 1;
    }
    if (poz == 0) {
        d2 = y + 1;
    }
    res += get_sum(max(0LL, d2 - (d1 - poz)), d2);
    //cout << d1 << " " << d2 << " " << y << " : " << res << endl;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sum[0] = 0;
    for (int i = 1; i < max_n; ++i) {
        sum[i] = sum[i - 1] + i;
    }
    cin >> a[0] >> a[1] >> a[2] >> x;
    for (int i = 0; i < 3; ++i) {
        int n1 = -1, n2 = -1;
        for (int j = 0; j < 3; ++j) {
            if (j != i) {
                if (n1 == -1) {
                    n1 = j;
                } else {
                    n2 = j;
                }
            }
        }
        for (int j = 0; j <= x; ++j) {
            long long y = x;
            b[0] = a[0];
            b[1] = a[1];
            b[2] = a[2];
            b[i] += j;
            y -= j;
            if (b[n1] >= b[i] || b[n2] >= b[i]) {
                continue;
            }
            long long d1 = b[i] - b[n1] - 1;
            long long d2 = b[i] - b[n2] - 1;
            long long mn = max(0LL, b[i] - b[n1] - b[n2] + 1);
            if (mn <= y) {
                ans += solve(d1, d2, y);
                if (mn > 0) {
                    ans -= solve(d1, d2, mn - 1);
                }
            }
        }
    }
    //cout << "1) " << ans << endl;
    sort(a, a + 3);
    proc();
    //cout << "2) " << ans << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            int n1;
            for (int k = 0; k < 3; ++k) {
                if (k != i && k != j) {
                    n1 = k;
                }
            }
            b[0] = a[0];
            b[1] = a[1];
            b[2] = a[2];
            long long y = x - (b[j] - b[i]);
            while (y >= 0) {
                ans += max(0LL, min(y + 1, b[j] - b[n1]));
                ++b[j];
                y -= 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}