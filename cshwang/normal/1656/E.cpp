#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

struct Link {
    int num ;
    Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
int T , n , cur , deg[MAX_N] , val[MAX_N] ;

void ins(int x , int y) {
    list[cur].num = y ;
    list[cur].next = head[x] ;
    head[x] = &list[cur++] ;
}

void dfs(int x , int f , int op) {
    val[x] = op * deg[x] ;
    for (Link *h = head[x] ; h ; h = h->next) {
        int nx = h->num ;
        if (nx == f) continue ;

        dfs(nx , x , -op) ;
    }
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ; cur = 0 ;
        for (int i = 1 ; i <= n ; ++i)
            deg[i] = 0 , head[i] = NULL ;
        for (int i = 1 ; i < n ; ++i) {
            int x , y ;
            scanf("%d %d" , &x , &y) ;
            ins(x , y) ; ins(y , x) ; ++deg[x] ; ++deg[y] ;
        }

        ///

        dfs(1 , 1 , 1) ;
        for (int i = 1 ; i <= n ; ++i) printf("%d " , val[i]) ;
        printf("\n") ;
    }

    return 0 ;
}