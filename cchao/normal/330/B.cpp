#include <cstdio>

int vis[1010] = {0};
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        vis[a] = vis[b] = 1;
    }
    printf("%d\n", n-1);
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) {
            for(int j = 1; j <= n; ++j)
                if(i != j) printf("%d %d\n", i, j);
            break;
        }
    return 0;
}