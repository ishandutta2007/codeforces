#include <cstdio>

#define M 10000010
int p[M], sz = 0;
int flag[M] = {0};
int main() {
    p[sz++] = 2;
    for(int i = 3; i < M; i += 2) {
        if(flag[i] == 0) {
            p[sz++] = i;
            for(int j = i, tmp = i+i; j < M; j += tmp)
                flag[j] = 1;
        }
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        printf("%d ", p[i]);
    puts("");
    return 0;
}