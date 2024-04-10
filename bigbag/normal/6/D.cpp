#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11, inf = 111111111;

int n, a, b, sum_h, h[max_n], ans, ans1[max_n], ans_num[max_n];

void gener(int sum, int kol, int poz) {
    if (h[poz - 2] >= 0 || kol > ans) return;
    if (poz == n) {
        /*if (sum < sum_h) {
            return;
        }*/
        for (int i = 1; i <= n; ++i) {
            if (h[i] >= 0) {
                return;
            }
        }
        if (kol < ans) {
            ans = kol;
            for (int i = 2; i < n; ++i) {
                ans_num[i] = ans1[i];
            }
        }
        return;
    }
    for (int i = 0; i <= 15 / b + 1; ++i) {
        ans1[poz] = i;
        h[poz] -= i * a;
        h[poz - 1] -= i * b;
        h[poz + 1] -= i * b;
        gener(sum + i * (a + 2 * b), kol + i, poz + 1);
        h[poz] += i * a;
        h[poz - 1] += i * b;
        h[poz + 1] += i * b;
    }
    return;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        sum_h += h[i];
    }
    ans = inf;
    h[0] = -1;
    gener(0, 0, 2);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < ans_num[i]; ++j) {
            cout << i << " ";
        }
    }
    return 0;
}