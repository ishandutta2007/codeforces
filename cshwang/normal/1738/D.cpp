#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

struct Link {
    int num ;
    Link *next ;
}list[MAX_N] ;

bool tg[MAX_N] ;
Link *head[MAX_N] ;
int T , n , tot , cur , ans[MAX_N] ;

void ins(int x , int y) {
    list[cur].num = y ;
    list[cur].next = head[x] ;
    head[x] = &list[cur++] ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        int k = 0 , p = -1 ; cur = tot = 0 ;
        for (int i = 0 ; i <= n + 1 ; ++i) tg[i] = 0 ;
        for (int i = 0 ; i <= n + 1 ; ++i) head[i] = NULL ;
        for (int i = 1 ; i <= n ; ++i) {
            int x ; scanf("%d" , &x) ;
            k = std::max(k , std::min(x , i)) ;
            ins(x , i) ;

            tg[x] = 1 ;
            if (!x || x == n + 1) p = x ;
        }

        ///

        for (; p != -1 ;) {
            int y = -1 ;
            for (Link *h = head[p] ; h ; h = h->next) {
                int nx = h->num ;
                if (tg[nx]) {y = nx ; break ;}
            }
            for (Link *h = head[p] ; h ; h = h->next) {
                int nx = h->num ;
                if (nx != y) ans[++tot] = nx ;
            }
            if (y != -1) ans[++tot] = y ;
            p = y ;
        }

        printf("%d\n" , k) ;
        for (int i = 1 ; i <= n ; ++i) printf("%d " , ans[i]) ;
        printf("\n") ;
    }

    return 0 ;
}