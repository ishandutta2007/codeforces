#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        set<int> q;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            q.insert(a[i]);
        }
        int ans = 0;
        while (!q.empty()) {
            int x = *q.rbegin();
            q.erase(x);
            if (x % 2 == 0) {
                x /= 2;
                ++ans;
                q.insert(x);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}