#include <map>
#include <set>
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

const int max_n = 44, max_m = 11, inf = 111111111;

int n, m, ans, poz, min1, a[max_m], x[max_n];
string s[max_m];

void gener(int p) {
    int l = 0;
    if (p == min1) {
        /*for (int i = 0; i < min1; ++i) {
            cout << x[i] << ' ';
        }
        cout << " - ";*/
        int cnt[max_m];
        for (int i = 0; i < m; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (l < min1 && i == x[l]) {
                for (int j = 0; j < m; ++j) {
                    if (s[j][i] == s[poz][i]) {
                        ++cnt[j];
                    }
                }
                ++l;
            } else {
                for (int j = 0; j < m; ++j) {
                    if (s[j][i] != s[poz][i]) {
                        ++cnt[j];
                    }
                }
            }
        }
        /*for (int i = 0; i < m; ++i) {
            cout << cnt[i] << ' ';
        }
        cout << endl;*/
        for (int i = 0; i < m; ++i) {
            if (cnt[i] != a[i]) {
                return;
            }
        }
        ++ans;
        return;
    }
    int st = 0;
    if (p != 0) {
        st = x[p - 1] + 1;
    }
    for (int i = st; i < n; ++i) {
        x[p] = i;
        gener(p + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    min1 = inf;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> a[i];
        if (a[i] < min1) {
            min1 = a[i];
            poz = i;
        }
    }
    ans = 0;
    gener(0);
    cout << ans << endl;
    return 0;
}