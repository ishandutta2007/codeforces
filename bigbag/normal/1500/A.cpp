/**
 *  created: 13/03/2021, 11:09:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;
const int max_x = 5000555;

int n, a[max_n];
vector<int> all[max_x];
pair<int, int> p[max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all[a[i]].push_back(i);
    }
    vector<int> v;
    for (int x = 0; x < max_x; ++x) {
        if (all[x].size() >= 2) {
            v.push_back(x);
        }
    }
    if (v.size() >= 2) {
        puts("YES");
        printf("%d %d %d %d\n", all[v[0]][0] + 1, all[v[1]][0] + 1, all[v[0]][1] + 1, all[v[1]][1] + 1);
        return 0;
    }
    if (v.size() == 1) {
        if (all[v[0]].size() >= 4) {
            puts("YES");
            for (int i = 0; i < 4; ++i) {
                printf("%d ", all[v[0]][i] + 1);
            }
            puts("");
            return 0;
        }
        for (int x = 0; x <= 2 * v[0]; ++x) {
            if (x == v[0]) {
                continue;
            }
            if (!all[x].empty() && !all[2 * v[0] - x].empty()) {
                puts("YES");
                printf("%d %d %d %d\n", all[v[0]][0] + 1, all[v[0]][1] + 1, all[x][0] + 1, all[2 * v[0] - x][0] + 1);
                return 0;
            }
        }
        for (int i = 1; i < all[v[0]].size(); ++i) {
            a[all[v[0]][i]] = -1;
        }
    }
    for (int i = 0; i < max_x; ++i) {
        p[i] = {-1, -1};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == -1 || a[j] == -1) {
                continue;
            }
            const int s = a[i] + a[j];
            if (p[s].first != -1 && a[i] != a[j]) {
                puts("YES");
                printf("%d %d %d %d", p[s].first + 1, p[s].second + 1, i + 1, j + 1);
                return 0;
            }
            p[s] = {i, j};
        }
    }
    puts("NO");
    return 0;
}