#include<cstdio>
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int hour, minute;
        scanf("%d%d", &hour, &minute);
        printf("%d\n", 24 * 60 - hour * 60 - minute);
    }
    return 0;
}