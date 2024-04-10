#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

struct Link {
    int num , id ;
    Link *next ;
}list[MAX_N << 1] ;
struct data {
    int x , y ;
}eg[MAX_N] , fa[MAX_N] ;

Link *head[MAX_N] ;
bool ap[MAX_N] , ans[MAX_N] ;
int T , n , m , cur , dep[MAX_N] ;

void init() {
    cur = 0 ;
    for (int i = 1 ; i <= n ; ++i) head[i] = NULL ;
}

void ins(int x , int y , int v) {
    list[cur].num = y ;
    list[cur].id = v ;
    list[cur].next = head[x] ;
    head[x] = &list[cur++] ;
}

void dfs(int x) {
    ap[x] = 1 ;
    for (Link *h = head[x] ; h ; h = h->next) {
        int nx = h->num ;
        if (ap[nx]) continue ;
        ans[h->id] = 1 ; dep[nx] = dep[x] + 1 ;
        fa[nx] = (data){x , h->id} ;
        dfs(nx) ;
    }
}

int main() {
    int T ; scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        init() ;
        for (int i = 1 ; i <= n ; ++i) ap[i] = 0 ;
        for (int i = 1 ; i <= m ; ++i) ans[i] = 0 ;
        for (int i = 1 ; i <= m ; ++i) {
            int x , y ; scanf("%d %d" , &x , &y) ;
            ins(x , y , i) ; ins(y , x , i) ;
            eg[i] = (data){std::min(x , y) , std::max(x , y)} ;
        }

        ///

        dep[1] = 1 ;
        fa[1] = (data){0 , 0} ;
        dfs(1) ;

        if (m == n + 2) {
            std::set<int> nde ;
            for (int i = 1 ; i <= m ; ++i)
                if (!ans[i]) {
                    nde.insert(eg[i].x) ;
                    nde.insert(eg[i].y) ;
                }
            
            if (nde.size() == 3) {
                int md = *nde.begin() ;
                for (auto &x : nde) if (dep[x] > dep[md]) md = x ;
                for (int i = 1 ; i <= m ; ++i)
                    if (!ans[i] && (eg[i].x == md || eg[i].y == md)) {
                        ans[i] = 1 ; break ;
                    }
                ans[fa[md].y] = 0 ;
            }
        }

        for (int i = 1 ; i <= m ; ++i)
            if (ans[i]) putchar('1') ;
            else putchar('0') ;
        printf("\n") ;
    }
}