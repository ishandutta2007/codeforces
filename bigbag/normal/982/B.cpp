#include <bits/stdc++.h>

using namespace std;

const int max_n = 400222, inf = 1000111222;

int n, a[max_n];
set<pair<int, int>> q[2];
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q[0].insert(make_pair(a[i], i));
    }
    scanf("%s", s);
    for (int i = 0; i < 2 * n; ++i) {
        int tp = s[i] - '0';
        int res = q[tp].begin()->second;
        q[tp].erase(q[tp].begin());
        printf("%d ", 1 + res);
        if (tp == 0) {
            q[1].insert(make_pair(-a[res], res));
        }
    }
    printf("\n");
    return 0;
}