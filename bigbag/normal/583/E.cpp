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

int n, a[max_n], f[max_n], mx[max_n], sum[max_n];
vector<int> q, g[max_n];
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
            q.clear();
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
                        q.push_back(j - poz);
                    }
                }
            }
            //cout << f1 << " " << f2 << endl;
            if (f1 != -1 && f2 != -1) {
                q.push_back(f1 + f2);
            } else {
                if (f1 != -1) {
                    q.push_back(f1);
                }
                if (f2 != -1) {
                    q.push_back(f2);
                }
            }
            sort(q.begin(), q.end());
            if (q.size() == 0) {
                continue;
            }
            /*cout << i << " : ";
            for (int j = 0; j < n; ++j) {
                cout << f[j] << " ";
            }
            cout << "  ";
            for (int j = 0; j < q.size(); ++j) {
                cout << q[j] << " ";
            }
            cout << endl;*/
            sum[0] = q[0];
            for (int j = 1; j < q.size(); ++j) {
                sum[j] = sum[j - 1] + q[j];
            }
            for (int j = 0; j < g[i].size(); ++j) {
                int s = g[i][j];
                //cout << "s = " << s << "  ans += ";
                if (s <= q.back()) {
                    if (q.back() == n) {
                        ans += n;
                        //cout << n << endl;
                    } else {
                        int l = lower_bound(q.begin(), q.end(), s) - q.begin();
                        ans += get_sum(l, q.size() - 1) - (q.size() - l) * (s - 1);
                        //cout << get_sum(l, q.size() - 1) - (q.size() - l) * (s - 1) << endl;
                    }
                } else {
                    //cout << 0 << endl;
                }
            }
            //cout << endl;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}