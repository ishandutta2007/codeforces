#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

int n, k, m, s, a[max_n], b[max_n];
int pos[max_n], c[max_n], need_c[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &k, &m, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all[a[i]].push_back(i);
    }
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < s; ++i) {
        scanf("%d", &b[i]);
        ++pos[b[i]];
        ++need_c[b[i]];
    }
    int last = 0;
    for (int i = 0; i < max_n; ++i) {
        if (pos[i] >= (int) all[i].size()) {
            puts("-1");
            return 0;
        } else if (pos[i] != -1) {
            last = max(last, all[i][pos[i]]);
        }
    }
    for (int i = 0; i + k <= n; ++i) {
        int cnt = i % k;
        int need = max(0, last - i + 1 - k);
        cnt += need;
        if (n - cnt >= m * k) {
            printf("%d\n", cnt);
            for (int j = 0; j < i % k; ++j) {
                printf("%d ", j + 1);
            }
            for (int j = i; j < n && need; ++j) {
                //cout << j << ": " << a[j] << ", " << c[a[j]] << " " << all[a[j]].size() << endl;
                if (c[a[j]] == need_c[a[j]]) {
                    printf("%d ", j + 1);
                    --need;
                } else {
                    ++c[a[j]];
                }
            }
            puts("");
            return 0;
        }
        if (all[a[i]].size()) {
            ++pos[a[i]];
            if (pos[a[i]] == all[a[i]].size()) {
                break;
            }
            last = max(last, all[a[i]][pos[a[i]]]);
        }
    }
    puts("-1");
    return 0;
}