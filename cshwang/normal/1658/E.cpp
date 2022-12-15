#include <bits/stdc++.h>

const int MAX_N = 4e3 + 10 , MAX_M = 4e6 + 10 ;

struct data {
    int x , y , val ;
}a[MAX_M] ;

bool ans[MAX_N][MAX_N] ;
int n , m , k , tot , B1[MAX_N] , B2[MAX_N] ;

bool cmp(data a , data b) {return a.val > b.val ;}

inline int lowbit(int x) {return x & (-x) ;}

void add(int* BIT , int x , int a) {
    for (; x <= m ; x += lowbit(x)) BIT[x] += a ;
}

void modify(int* BIT , int x , int y) {
    x = std::min(x , m) ; y = std::max(1 , y) ;
    if (x > y) return ;
    add(BIT , x , 1) ; add(BIT , y + 1 , -1) ;
}

int calc(int* BIT , int x) {
    int s = 0 ;
    for (; x ; x -= lowbit(x)) s += BIT[x] ;

    return s ;
}

int main() {
    scanf("%d %d" , &n , &k) ; ++k ; m = n << 1 ;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j) {
            int num ; scanf("%d" , &num) ;
            a[tot++] = (data){i + j , i - j + n , num} ;
        }
    std::sort(a + 0 , a + tot , cmp) ;

    ///

    for (int i = 0 ; i < tot ; ++i) {
        data *p = &a[i] ;
        int sta = calc(B1 , p->x) + calc(B2 , p->y) ;
        if (sta) ans[(p->x + p->y - n) / 2][(p->x - p->y + n) / 2] = 0 ;
        else {
            ans[(p->x + p->y - n) / 2][(p->x - p->y + n) / 2] = 1 ;
            modify(B1 , 1 , p->x - k) ; modify(B1 , p->x + k , m) ;
            modify(B2 , 1 , p->y - k) ; modify(B2 , p->y + k , m) ;
        }
    }

    for (int i = 1 ; i <= n ; ++i , printf("\n"))
        for (int j = 1 ; j <= n ; ++j)
            if (ans[i][j]) printf("M") ;
            else printf("G") ;

    return 0 ;
}