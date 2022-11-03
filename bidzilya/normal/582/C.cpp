#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
#include <unordered_map>
using namespace std;

int GetGcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    long long ans = 0;
    vector<int> mx(n);
    vector<int> g(n);
    for (int i = 1; i < n; ++i) {
        g[i] = GetGcd(i, n);
    }
    vector<int> b(2 * n);
    vector<long long> sa(n), sb(n);
    for (int d = 1; d < n; ++d) {
        if (n % d == 0) {
            for (int i = 0; i < d; ++i) {
                mx[i] = a[i];
            }
            for (int i = 0; i < d; ++i) {
                for (int j = i; j < n; j += d) {
                    mx[i] = max(mx[i], a[j]);
                }
            }
            b.assign(2 * n, 0);
            for (int i = 0; i < d; ++i) {
                for (int j = i; j < 2 * n; j += d) {
                    if (a[j] == mx[i]) {
                        b[j] = 1;
                    }
                }
            }
            sa.assign(2 * n + 1, 0);
            for (int i = 0; i < n; ++i) {
                if (b[i] == 1) {
                    int j = i;
                    while (j + 1 < 2 * n && b[j + 1] == 1) {
                        ++j;
                    }
                    ++sa[j - i + 1];
                    if (j >= n) {
                        --sa[j - n + 1];
                    }
                    i = j;
                }
            }
            sb.assign(2 * n + 1, 0);
            long long cur_sum = 0;
            long long amount = 0;
            for (int i = 2 * n; i >= 0; --i) {
                amount += sa[i];
                cur_sum += amount;
                sb[i] = cur_sum;
            }
            for (int s = 1; s < n; ++s) {
                if (g[s] == d) {
                    ans += sb[s];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}