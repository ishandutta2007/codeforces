/**
 *  created: 30/05/2021, 17:50:53
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, a[max_n], ok[max_n][2];
vector<int> ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        memset(ok, 0, sizeof(ok));
        scanf("%d", &n);
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (i == 0) {
                assert(a[i] == 1);
                ans[i] = {a[i]};
            } else {
                //for (int j = 0; j < i; ++j) {
                while (true) {
                    int j = v.back();
                    if (ans[j].back() + 1 == a[i] && !ok[j][0]) {
                        ok[j][0] = 1;
                        ans[i] = ans[j];
                        ++ans[i].back();
                        break;
                    }
                    if (!ok[j][1] && a[i] == 1) {
                        ok[j][1] = 1;
                        ans[i] = ans[j];
                        ans[i].push_back(a[i]);
                        break;
                    }
                    v.pop_back();
                }
            }
            v.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            printf("%d", ans[i][0]);
            for (int j = 1; j < ans[i].size(); ++j) {
                printf(".%d", ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}