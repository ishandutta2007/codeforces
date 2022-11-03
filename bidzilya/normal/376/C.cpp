#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_n = 1e6 + 100;

int a[4];
string s;
int us[10];
int pw[max_n];
int ans[max_n];
int sz = 0;

int main() {
    ios_base::sync_with_stdio(false);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i)
        pw[i] = (pw[i - 1] * 10) % 7;
    cin >> s;
    for (int i = 0; i < (int) s.length(); ++i) {
        int k = s[i] - '0';
        if ((k == 1 || k == 6 || k == 8 || k == 9) && !us[k]) {
            us[k] = 1;
            continue;
        }
        ans[sz] = k;
        ++sz;
    }
    a[0] = 1;
    a[1] = 6;
    a[2] = 8;
    a[3] = 9;
    int ost = 0;
    for (int i = 0; i < sz; ++i)
        ost = (ost + ans[i] * pw[i]) % 7;
    for (int i = 0; i < 24; ++i) {
        int cur_ost = ost;
        for (int j = 0; j < 4; ++j) {
            cur_ost = (cur_ost + a[j] * pw[sz + j]) % 7;
        }
        if (cur_ost == 0) {
            for (int j = 0; j < 4; ++j) {
                ans[sz] = a[j];
                ++sz;
            }
            break;
        }
        next_permutation(a, a + 4);
    }
    for (int i = sz - 1; i >= 0; --i)
        cout << ans[i];
    cout << endl;
    return 0;
}