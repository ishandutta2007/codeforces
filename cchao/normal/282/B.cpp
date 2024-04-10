#include <cstdio>
int main(){
    int n, a, b, ta, tb; scanf("%d", &n);
    while(n--){
        scanf("%d%d", &ta, &tb);
        if(a+ta-b<=500){putchar('A'); a+=ta;}
        else{putchar('G'); b+=tb;}
    }
    puts("");
    return 0;
}