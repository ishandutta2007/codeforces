#include <bits/stdc++.h>
using namespace std;
int buc[210];
int n, k;
char s[210];
void rmain() {
    memset(buc, 0, sizeof buc);
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) buc[s[i] - 'a']++;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n / k; j++) if (j == n / k || buc[j] < i) {
            putchar(j + 'a');
            break;
        }
    }
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}