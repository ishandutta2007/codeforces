#include <bits/stdc++.h>

int T , x , y ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &x , &y) ;
        printf("%d %d\n" , x , (x << 1)) ;
    }

    return 0 ;
}