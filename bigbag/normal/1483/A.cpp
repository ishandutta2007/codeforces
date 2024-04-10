/**
 *  created: 21/03/2021, 15:28:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, m, cnt[max_n], ans[max_n];
vector<int> ids[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        cnt[i] = 0;
    }
}

bool solve() {
    const int mx = (m + 1) / 2;
    for (int i = 0; i < m; ++i) {
        if (ids[i].size() == 1) {
            ans[i] = ids[i][0];
            ++cnt[ans[i]];
            if (cnt[ans[i]] > mx) {
                return false;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ids[i].size() > 1) {
            int pos = 0;
            for (int j = 1; j < ids[i].size(); ++j) {
                if (cnt[ids[i][j]] < cnt[ids[i][pos]]) {
                    pos = j;
                }
            }
            ans[i] = ids[i][pos];
            ++cnt[ans[i]];
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        clr();
        for (int i = 0; i < m; ++i) {
            int k;
            scanf("%d", &k);
            ids[i].resize(k);
            for (int &id : ids[i]) {
                scanf("%d", &id);
                --id;
            }
        }
        if (solve()) {
            puts("YES");
            for (int i = 0; i < m; ++i) {
                printf("%d ", ans[i] + 1);
            }
            puts("");
        } else {
            puts("NO");
        }
    }
    return 0;
}