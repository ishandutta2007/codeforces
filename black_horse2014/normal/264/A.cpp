#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

char s[N];
int id[N], ans[N];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int l = n, r = n;
    ans[n] = n;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == 'l') {
            ans[i] = ++r;
        } else {
            ans[i] = --l;
        }
    }
    for (int i = 1; i <= n; i++) id[i] = i;
    sort(id + 1, id + n + 1, [](int u, int v) {
        return ans[u] < ans[v];
    });
    for (int i = 1; i <= n; i++) printf("%d\n", id[i]);
    return 0;
}