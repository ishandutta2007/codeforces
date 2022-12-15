#include <bits/stdc++.h>

int T , n ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; ; ++i) {
            int tmp = n * i ;
            if (tmp % 180) continue ;
            tmp /= 180 ;
            if (tmp < i - 1) {printf("%d\n" , i) ; break ;}
        }
    }

    return 0 ;
}