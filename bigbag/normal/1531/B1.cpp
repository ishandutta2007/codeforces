/**
 *  created: 24/05/2021, 12:25:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n, a[max_n], b[max_n];
map<int, int> cnt;
map<pair<int, int>, int> cnt2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        ++cnt2[{a[i], b[i]}];
        ++cnt[a[i]];
        if (a[i] != b[i]) {
            ++cnt[b[i]];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        --cnt[a[i]];
        if (a[i] != b[i]) {
            --cnt[b[i]];
        }
        ans += cnt[a[i]];
        if (a[i] != b[i]) {
            ans += cnt[b[i]];
            ans -= cnt2[{a[i], b[i]}] - 1;
        }
        ++cnt[a[i]];
        if (a[i] != b[i]) {
            ++cnt[b[i]];
        }
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << "\n";
    return 0;
}