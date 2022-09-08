#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111;

int n, a[max_n], sum1[max_n], sum2[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sum1[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum1[i] = sum1[i - 1] + a[i];
    }
    sum2[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sum2[i] = sum2[i + 1] + a[i];
    }
    int x = 0, y = n - 1, ans1 = 0, ans2 = 0;
    while (ans1 + ans2 < n) {
        int k = x, k1 = y;
        if (sum1[k] < sum2[k1]) {
            ans1++;
            x++;
        }
        if (sum1[k] > sum2[k1]) {
            ans2++;
            y--;
        }
        if (sum1[k] == sum2[k1]) {
            if (k == k1) {
                ans1++;
                x++;
            }
            else {
                ans1++;
                x++;
                ans2++;
                y--;
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}