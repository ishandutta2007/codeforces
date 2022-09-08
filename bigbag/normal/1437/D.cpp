#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], h[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i < n; ++i) {
            int pos = i;
            while (i + 1 < n && a[i] < a[i + 1]) {
                ++i;
            }
            v.push_back(i - pos + 1);
        }
        int cnt = 1, ans = 0;
        for (int i = 1; i < v.size(); ) {
            ++ans;
            if (i + cnt - 1 >= v.size()) {
                break;
            }
            int ncnt = 0;
            for (int j = i; j < i + cnt; ++j) {
                ncnt += v[j];
            }
            i += cnt;
            cnt = ncnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}