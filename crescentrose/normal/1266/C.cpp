#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    if (n == 1 && m == 1) {
        printf("0");
        return 0;
    }
    if (m == 1){
        for (int i = 2; i <=n + 1 ; i++)
            printf("%d\n", i);
        return 0;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1;j  <=m ; j ++)
            printf("%d ", i * (n + j));
        printf("\n");
    }
    return 0;
}