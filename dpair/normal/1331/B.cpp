#include <cstdio>
int x;
int main(){
    scanf("%d", &x);
    for (int i = 2;i <= x;++ i){
        if(x % i == 0){
            printf("%d%d\n", i, x / i);
            return 0;
        }
    }
}