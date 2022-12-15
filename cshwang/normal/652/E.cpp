#include <bits/stdc++.h>

const int MAX_N = 3e5 + 10 ;

int n , m , S , T , col[MAX_N] ;

namespace BCC {
    struct Edge {int u , v , c ;} ;
    struct Link {
        Link *next ;
        int num , val ;

        void Init() {num = val = 0 ; next = NULL ;}
    } ;
    
    Link *head[MAX_N] ;
    Link list[MAX_N << 1] ;
    int n , Ti , cur , tcol , dfn[MAX_N] , low[MAX_N] , col[MAX_N] ;

    std::vector<Edge> eg ;
    std::vector<int> sta ;

    void Init(int __n) {
        n = __n ;
        sta.clear() ; eg.clear() ;
        for (int i = 0 ; i < cur ; ++i) list[i].Init() ;
        for (int i = 0 ; i <= n ; ++i) head[i] = NULL , dfn[i] = low[i] = col[i] = 0 ;
        Ti = tcol = cur = 0 ;
    }
    void RebuildInit() {
        for (int i = 0 ; i < cur ; ++i) list[i].Init() ;
        for (int i = 0 ; i <= n ; ++i) head[i] = NULL , dfn[i] = low[i] = 0 ;
        Ti = cur = 0 ;
    }
    void AddEdge(int x , int y , int v , int ty) {
        list[cur].num = y ;
        list[cur].val = v ;
        list[cur].next = head[x] ;
        head[x] = &list[cur++] ;

        list[cur].num = x ;
        list[cur].val = v ;
        list[cur].next = head[y] ;
        head[y] = &list[cur++] ;

        if (!ty) eg.push_back((Edge){x , y , v}) ;
    }
    void DfsEdge(int x , int fa) {
        sta.push_back(x) ;
        dfn[x] = low[x] = ++Ti ;

        for (Link *h = head[x] ; h ; h = h->next) {
            int nx = h->num , eid = h - list ;
            if ((eid ^ 1) == fa) continue ;

            if (dfn[nx]) low[x] = std::min(low[x] , dfn[nx]) ;
            else {
                DfsEdge(nx , eid) ;
                low[x] = std::min(low[x] , low[nx]) ;
            }
        }

        if (dfn[x] == low[x]) {
            col[x] = ++tcol ;
            for (; sta.back() != x ;) {
                int tp = sta.back() ;
                col[tp] = tcol ; sta.pop_back() ;
            }
            sta.pop_back() ;
        }
    }
    void EdgeBCC() {
        for (int i = 1 ; i <= n ; ++i)
            if (!dfn[i]) DfsEdge(i , -1) ;
        
        RebuildInit() ;
        for (auto &x : eg) {
            if (col[x.u] == col[x.v]) continue ;
            AddEdge(col[x.u] , col[x.v] , x.c , 1) ;
        }
    }
} ;

void dfs(int x , int fa) {
    for (BCC::Link *h = BCC::head[x] ; h ; h = h->next) {
        int nx = h->num ;
        if (nx == fa) continue ;

        col[nx] |= h->val | col[x] ;
        dfs(nx , x) ;
    }
}

int main() {
    scanf("%d %d" , &n , &m) ;
    BCC::Init(n) ;
    for (int i = 0 ; i < m ; ++i) {
        int x , y , c ; scanf("%d %d %d" , &x , &y , &c) ;
        BCC::AddEdge(x , y , c , 0) ;
    }

    ///

    BCC::EdgeBCC() ;
    for (auto &x : BCC::eg)
        if (BCC::col[x.u] == BCC::col[x.v]) {
            int c = BCC::col[x.u] ;
            col[c] |= x.c ;
        }

    scanf("%d %d" , &S , &T) ;
    S = BCC::col[S] ; T = BCC::col[T] ;
    dfs(S , S) ;

    if (col[T]) printf("YES\n") ;
    else printf("NO\n") ;

    return 0 ;
}