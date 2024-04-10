#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n];
vector<int> cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ) {
        int st = i;
        while (i < n && a[i] == a[st]) {
            ++i;
        }
        cnt.push_back(i - st);
    }
    sort(cnt.begin(), cnt.end());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int res = 0, cur = i, pos = 0;
        while (pos < cnt.size()) {
            auto it = lower_bound(cnt.begin() + pos, cnt.end(), cur);
            if (it == cnt.end()) {
                break;
            }
            res += cur;
            cur *= 2;
            pos = it - cnt.begin() + 1;
        }
        ans = max(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}