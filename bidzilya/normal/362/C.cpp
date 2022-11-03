#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 5e3 + 100;

int n;
int a[max_n];
int cnt[max_n][max_n];

int cnt_more(int l, int r, int d) {
    return cnt[d][r] - cnt[d][l - 1];
}

int cnt_less(int l, int r, int d) {
    return r - l + 1 - cnt_more(l, r, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++a[i];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cnt[i][j] = cnt[i][j - 1] + (a[j] > i);
    int inv = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[j] < a[i])
                ++inv;
    int mn = inv, cmn = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            int cinv = inv;
            if (i + 1 < j) {
                cinv -= cnt_more(i + 1, j - 1, a[j]);
                cinv += cnt_less(i + 1, j - 1, a[j]);
                cinv += cnt_more(i + 1, j - 1, a[i]);
                cinv -= cnt_less(i + 1, j - 1, a[i]);
            }
            if (a[i] < a[j]) ++cinv;
            if (a[i] > a[j]) --cinv;
            if (cinv == mn) {
                ++cmn;
            } else if (cinv < mn) {
                mn = cinv;
                cmn = 1;
            }
        }
    cout << mn << " " << cmn << endl;
    return 0;
}