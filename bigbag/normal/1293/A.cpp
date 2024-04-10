#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int t, mx, s, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &mx, &s, &n);
        set<int> q;
        while (n--) {
            int x;
            scanf("%d", &x);
            q.insert(x);
        }
        for (int i = 0; ; ++i) {
            if ((s - i > 0 && !q.count(s - i)) || (s + i <= mx && !q.count(s + i))) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}