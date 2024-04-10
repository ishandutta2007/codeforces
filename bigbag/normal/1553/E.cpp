/**
 *  created: 22/07/2021, 18:15:07
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, m, a[max_n], used[max_n], pos[max_n];

bool check(int k) {
    rotate(a, a + k, a + n);

    for (int i = 0; i < n; ++i) {
        used[i] = 0;
        pos[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int x = i;
            while (!used[x]) {
                used[x] = 1;
                x = a[x];
                ++ans;
            }
            --ans;
        }
    }

    rotate(a, a + n - k, a + n);

    return ans <= m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
        }
        map<int, int> cands;
        for (int i = 0; i < n; ++i) {
            int k = i - a[i];
            if (k < 0) {
                k += n;
            }
            ++cands[k];
        }
        vector<int> ans;
        for (auto p : cands) {
            if (p.second >= n - 2 * m) {
                if (check(p.first)) {
                    ans.push_back(p.first);
                }
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d", ans.size());
        for (int x : ans) {
            printf(" %d", x);
        }
        puts("");
    }
    return 0;
}