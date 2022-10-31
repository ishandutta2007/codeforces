#include <cstdio>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    if(k*3 > n){
        puts("-1"); return 0;
    }
    int nn = n-k;
    int div = nn/k, mod = nn % k;
    for(int i = 0; i < k; ++i){
        int cnt = div;
        if(i < mod) cnt++;
        while(cnt--) printf("%d ", i+1);
    }
    for(int i = 0; i < k; ++i) printf("%d ", i+1);
    puts("");
    return 0;
}