#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
vector<pair<int, int>> ans;
vector<int> all[4];

void wa() {
    puts("-1");
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all[a[i]].push_back(i);
    }
    int mx = n - 1;
    for (int i = 0; i + 1 < all[3].size(); ++i) {
        ans.push_back({all[3][i], mx});
        ans.push_back({all[3][i + 1], mx});
        --mx;
    }
    bool ok = 1;
    if (!all[3].empty()) {
        ok = 0;
        for (int i = all[3].back() + 1; i < n; ++i) {
            if (a[i] == 2) {
                ok = 1;
                ans.push_back({all[3].back(), mx});
                ans.push_back({i, mx});
                --mx;
                break;
            }
        }
        if (!ok) {
            for (int i = all[3].back() + 1; i < n; ++i) {
                if (a[i] == 1) {
                    ok = 1;
                    all[1].erase(find(all[1].begin(), all[1].end(), i));
                    ans.push_back({all[3].back(), mx});
                    ans.push_back({i, mx});
                    ans.push_back({i, mx - 1});
                    mx -= 2;
                    break;
                }
            }
        }
        if (!ok) {
            wa();
        }
    }
    set<int> all1(all[1].begin(), all[1].end());
    for (int pos : all[2]) {
        auto it = all1.lower_bound(pos);
        if (it == all1.end()) {
            wa();
        }
        int x = *it;
        all1.erase(it);
        ans.push_back({pos, mx});
        ans.push_back({x, mx});
        --mx;
    }
    for (int pos : all1) {
        ans.push_back({pos, mx});
        --mx;
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", n - p.second, p.first + 1);
        //printf("%d %d\n", p.first + 1, p.second + 1);
    }
    return 0;
}