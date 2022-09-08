#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, a[max_n];
int cur, last[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        vector<int> ans;
        while (true) {
            while (n && a[n - 1] == n) {
                n--;
            }
            if (!n) {
                break;
            }
            ++cur;
            for (int i = 0; i < n; ++i) {
                last[a[i]] = cur;
            }
            int x;
            for (int i = 0; ; ++i) {
                if (last[i] != cur) {
                    x = i;
                    break;
                }
            }
            if (x == n) {
                ans.push_back(n - 1);
                a[n - 1] = x;
            } else {
                ans.push_back(x);
                a[x] = x;
            }
        }
        printf("%d\n", ans.size());
        for (int pos : ans) {
            printf("%d ", pos + 1);
        }
        puts("");
    }
    return 0;
}