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

const int max_n = 505, inf = 1111111111;

int n, a[max_n * max_n], b[max_n * max_n], q1[max_n * max_n];
map<int, int> q2, q3;
vector<int> v1, v2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n * n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n * n);
    int cnt = 0;
    for (int i = 0; i < n * n;) {
        b[cnt] = a[i];
        int poz = i;
        while (i < n * n && a[i] == a[poz]) {
            ++i;
        }
        q1[cnt] = i - poz;
        ++cnt;
    }

    /*for (int i = cnt - 1; i >= 0; --i) {
        cout << b[i] << " " << q1[i] << endl;
    }*/
    for (int i = cnt - 1; i >= 0; --i) {
        int l = 0, r = n + 1;
        int Q2 = q2[b[i]], Q3 = q3[b[i]];
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (Q2 + mid * mid + 2 * mid * Q3 <= q1[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int ans = l;
        for (int j = 0; j < ans; ++j) {
            printf("%d ", b[i]);
        }
        for (int j = 0; j < v1.size(); ++j) {
            q2[__gcd(b[i], v1[j])] += 2 * ans * v2[j];
        }
        for (int j = 1; j * j <= b[i]; ++j) {
            if (b[i] % j == 0) {
                q3[j] += ans;
                if (b[i] / j > j) {
                    q3[b[i] / j] += ans;
                }
            }
        }
        v1.push_back(b[i]);
        v2.push_back(ans);
    }
    return 0;
}