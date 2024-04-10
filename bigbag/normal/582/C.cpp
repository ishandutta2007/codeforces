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

const int max_n = 211111, inf = 1111111111;

int n, qsz, a[max_n], f[max_n], mx[max_n], sum[max_n], q[max_n];
vector<int> g[max_n];
long long ans;

int get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        g[__gcd(i, n)].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size()) {
            for (int j = 0; j < i; ++j) {
                mx[j] = -1;
                for (int k = j; k < n; k += i) {
                    mx[j] = max(mx[j], a[k]);
                }
            }
            for (int j = 0; j < n; ++j) {
                f[j] = 0;
                if (a[j] == mx[j % i]) {
                    f[j] = 1;
                }
            }
            qsz = 0;
            int f1 = -1, f2 = -1;
            for (int j = 0; j < n; ++j) {
                int poz = j;
                while (j < n && f[j] == 1) {
                    ++j;
                }
                if (j != poz) {
                    if (poz == 0) {
                        f1 = j - poz;
                    } else if (j == n) {
                        f2 = j - poz;
                    } else {
                        q[qsz] = j - poz;
                        ++qsz;
                    }
                }
            }
            //cout << f1 << " " << f2 << endl;
            if (f1 != -1 && f2 != -1) {
                q[qsz] = f1 + f2;
                ++qsz;
            } else {
                if (f1 != -1) {
                    q[qsz] = f1;
                    ++qsz;
                }
                if (f2 != -1) {
                    q[qsz] = f2;
                    ++qsz;
                }
            }
            sort(q, q + qsz);
            sum[0] = q[0];
            for (int j = 1; j < qsz; ++j) {
                sum[j] = sum[j - 1] + q[j];
            }
            for (int j = 0; j < g[i].size(); ++j) {
                int s = g[i][j];
                if (s <= q[qsz - 1]) {
                    if (q[qsz - 1] == n) {
                        ans += n;
                    } else {
                        int l = lower_bound(q, q + qsz, s) - q;
                        ans += get_sum(l, qsz - 1) - (qsz - l) * (s - 1);
                    }
                }
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}