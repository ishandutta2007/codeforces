#include<cstdio>
#include<cstdlib>
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            printf("%d", (abs(i-1)+8)%10);
        }
        puts("");
    }
    return 0;
}