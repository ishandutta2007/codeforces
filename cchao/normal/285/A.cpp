#include <cstdio>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a = k, b = n-k, t = n;
    while(a--) printf("%d ", t--);
    t=1;
    while(b--) printf("%d ", t++);
    puts("");
    return 0;
}