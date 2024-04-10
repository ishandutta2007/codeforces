#include <stdio.h>

int main() {
    int k, n; scanf("%d%d", &n, &k);
    int i, m = 1;
    for(i = 1; i <= 2 * n; i += 2) {
        if(k-- > 0) printf("%d %d ", i, i+1);
        else printf("%d %d ", i+1, i);
    }
    puts("");
    return 0;
}