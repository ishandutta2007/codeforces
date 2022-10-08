#include <stdio.h>
int cnt[10] = {2,7,2,3,3,4,2,5,1,2};
int main() {
    int N;
    scanf("%d", &N);
    printf("%d", cnt[N/10]*cnt[N%10]);
    return 0;
}