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

const int max_n = 1111, inf = 1111111111;

int n, t, r, ans, a[max_n], cnt[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t >> r;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x += 333;
        a[x] = r;
    }
    for (int i = 0; i < max_n; ++i) {
        int poz = i - 1;
        while (a[i] > 0) {
            if (poz + r < i) {
                cout << -1 << endl;
                return 0;
            }
            if (used[poz] == 0) {
                ++ans;
                used[poz] = 1;
                for (int j = poz + 1; j < poz + 1 + t; ++j) {
                    --a[j];
                }
            }
            --poz;
        }
    }
    cout << ans << endl;
    return 0;
}