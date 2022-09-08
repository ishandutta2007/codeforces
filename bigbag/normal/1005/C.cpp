#include <bits/stdc++.h>

using namespace std;

const int max_n = 122222, inf = 1000111222;

int n, a[max_n];
map<int, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++q[a[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = false;
        for (int pw = 0; pw < 31; ++pw) {
            if (q.count((1 << pw) - a[i])) {
                if (2 * a[i] == (1 << pw)) {
                    if (q[a[i]] > 1) {
                        ok = true;
                        break;
                    }
                } else {
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}