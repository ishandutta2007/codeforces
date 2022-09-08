#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, k, a[max_n], cnt[max_n];
vector<pair<int, int>> all;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 1; j <= cnt[i]; ++j) {
            all.push_back({cnt[i] / j, i});
        }
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < k; ++i) {
        printf("%d ", all[i].second);
    }
    puts("");
    return 0;
}