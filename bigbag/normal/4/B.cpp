#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 33, inf = 111111111;

int n, sum_t, x, y, a[max_n], a1[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> sum_t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> a1[i];
        x += a[i];
        y += a1[i];
    }
    if (x <= sum_t && sum_t <= y) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            ans[i] = a[i];
        }
        int poz = 0;
        while (sum_t - x > 0) {
            if (ans[poz] < a1[poz])
            {
                x++;
                ans[poz]++;
            }
            else poz++;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
    }
    else cout << "NO";
    return 0;
}