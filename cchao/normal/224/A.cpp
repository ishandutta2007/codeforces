#include <cstdio>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 1; i <= a; ++i){
        if(a%i || b%i) continue;
        if((a/i) * (b/i) == c){
            printf("%d\n", (i+(a/i)+(b/i)<<2));
            return 0;
        }
    }
}