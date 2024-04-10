#include <stdio.h>
int main(void){
    int a = 0, b = 0, c = 1, d, n;
    scanf("%d", &n );
    
    if( !n ){
        puts("0 0 0");
    }
    else{
        while( ( d = b + c ) != n ){
            a = b;
            b = c;
            c = d;
        }
        
        printf("%d %d %d\n", b - a, a, c );
    }
    return 0;
}