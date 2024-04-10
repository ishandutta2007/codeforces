#include <stdio.h>

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int ans = 4, t, i, j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j) {
            scanf("%d", &t);
            if(t == 1) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                    ans = 2;
            }
        }
    printf("%d\n", ans);
    return 0;
}