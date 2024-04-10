#include <map>
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

const int max_n = 311111, inf = 111111111;

int n, ans[max_n];
pair <int, int> a[max_n];
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int firsta = -1;
    for (int i = 0; i < n; ++i) {
        int poz = i;
        while (poz + 1 < n && a[poz].first == a[poz + 1].first) {
            ++poz;
        }
        if (a[i].first > firsta) {
            for (int j = i; j <= poz; ++j) {
                ans[a[j].second] = a[i].first + j - i;
            }
            firsta = a[i].first + poz - i;
        } else {
            int x = firsta - a[i].first + 1;
            for (int j = i; j <= poz; ++j) {
                ans[a[j].second] = a[i].first + x + j - i;
            }
            firsta = a[i].first + x + poz - i;
        }
        i = poz;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}