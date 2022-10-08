#include <stdio.h>
#include <algorithm>
int a[100050];
int b[100050];
int c[100050];
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &a[i]);
    for(i = 1; i <= N-1; i++) scanf("%d", &b[i]);
    for(i = 1; i <= N-2; i++) scanf("%d", &c[i]);
    std::sort(a+1, a+N+1);
    std::sort(b+1, b+N);
    std::sort(c+1, c+N-1);
    for(i = 1; i <= N-1; i++) {
        if(a[i] != b[i]) break;
    }
    printf("%d\n", a[i]);
    for(i = 1; i <= N-2; i++) {
        if(b[i] != c[i]) break;
    }
    printf("%d\n", b[i]);
    return 0;
}