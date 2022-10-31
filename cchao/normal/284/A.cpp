#include <cstdio>

int test(int n, int p){
    int x = 1;
    for(int i = 0; i < p-2; ++i){
        x*=n; x%=p;
        if(x==1) return 0;
    }
    return 1;
}

int main(){
    int n, ans=0;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        ans += test(i, n);
    }
    printf("%d\n", ans);
    return 0;
}