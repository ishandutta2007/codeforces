/**
 *  created: 25/07/2021, 18:06:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int t, n, a[max_n];
bool ans;

void rec(int pos, int sum, int cnt) {
    if (pos == n) {
        if (cnt && sum == 0) {
            ans = 1;
        }
        return;
    }
    rec(pos + 1, sum, cnt);
    rec(pos + 1, sum + a[pos], cnt + 1);
    rec(pos + 1, sum - a[pos], cnt + 1);
}

bool solve() {
    ans = 0;
    rec(0, 0, 0);
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}