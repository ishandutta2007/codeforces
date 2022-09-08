#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, a[max_n], pos[max_n];
pair<int, int> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        a[p[i].second] = i;
    }
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += a[i] > a[j];
        }
    }
    vector<int> all;
    for (int i = 1; i < n; ++i) {
        if (pos[i] < pos[i - 1]) {
            all.push_back(i);
        }
    }
    printf("%d\n", ans);
    while (!all.empty()) {
        int x = all.back();
        all.pop_back();
        if (pos[x] > pos[x - 1]) {
            continue;
        }
        printf("%d %d\n", pos[x] + 1, pos[x - 1] + 1);
        swap(a[pos[x]], a[pos[x - 1]]);
        swap(pos[x], pos[x - 1]);
        if (x + 1 < n && pos[x + 1] < pos[x]) {
            all.push_back(x + 1);
        }
        if (x - 2 >= 0 && pos[x - 1] < pos[x - 2]) {
            all.push_back(x - 1);
        }
    }
    return 0;
}