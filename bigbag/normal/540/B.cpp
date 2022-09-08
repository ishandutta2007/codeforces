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

const int max_n = 11111, inf = 1111111111;

int n, k, p, x, y, sum, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> p >> x >> y;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int mid = y; mid <= p; ++mid) {
        b[n / 2] = mid;
        int poz1 = 0, poz2 = n / 2 + 1, cnt = 0, f = 0;
        for (int i = 0; i < k; ++i) {
            if (a[i] < mid) {
                b[poz1] = a[i];
                ++poz1;
            } else if (a[i] > mid) {
                b[poz2] = a[i];
                ++poz2;
            } else {
                ++cnt;
                if (cnt == 1) {
                    f = 1;
                }
            }
        }
        cnt -= f;
        while (poz2 < n && cnt) {
            --cnt;
            b[poz2] = mid;
            ++poz2;
        }
        while (poz1 < n / 2 && cnt) {
            --cnt;
            b[poz1] = mid;
            ++poz1;
        }
        --poz1;
        --poz2;
        if (poz1 >= n / 2 || poz2 >= n) {
            continue;
        }
        int r1 = n / 2 - poz1 - 1;
        int r2 = n - poz2 - 1;
        int xx = 0;
        if (f == 1) {
            xx = -mid;
        }
        //cout << mid << " ! " << xx << "  " << sum + mid + xx + r1 + r2 * mid  << "  " << poz2 << endl;
        if (sum + mid + xx + r1 + r2 * mid <= x) {
            for (int i = 0; i < r1; ++i) {
                cout << "1 ";
            }
            for (int i = 0; i < r2 + 1 - f; ++i) {
                cout << mid << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}