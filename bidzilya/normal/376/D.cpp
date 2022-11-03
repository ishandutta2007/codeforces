#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_n = 5e3 + 100;

int n, m;
string s[max_n];
int c[max_n], t[max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans_sq = 0;
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == '0') {
                c[i] = 0;
            } else {
                c[i] = c[i] + 1;
            }
        }
        for (int k = 0; k <= m - j; ++k)
            t[k] = 0;
        for (int i = 0; i < n; ++i)
            ++t[c[i]];
        for (int k = m - j - 1; k >= 0; --k)
            t[k] += t[k + 1];
        for (int k = 0; k <= m - j; ++k) {
            int cur_sq = k * t[k];
            ans_sq = max(ans_sq, cur_sq);
        }
    }
    cout << ans_sq << endl;
    return 0;
}