#include <cstdio>
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if(m==3 && n > 4){
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= m; ++i)
        printf("%d %d\n", i, i*i);
    for(int i = 1; i <= n-m; ++i)
        printf("%d %d\n", i, -1000000-i*i);
    return 0;
}