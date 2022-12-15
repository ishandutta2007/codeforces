#include <bits/stdc++.h>

#define ll long long

const ll INF = 0x3f3f3f3f ;
const int MAX_N = 500 + 10 ;

struct Edge {
    int x , y , v ;
}eg[MAX_N * MAX_N] ;
struct data {
    int val , idx ;

    friend bool operator <(data a , data b) {return a.val > b.val ;}
} ;

std::priority_queue<data> que ;

int T , n , m , gt[MAX_N] , d[MAX_N][MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &m) ;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                if (i == j) d[i][j] = 0 ;
                else d[i][j] = INF ;
        for (int i = 0 ; i < m ; ++i) {
            scanf("%d %d %d" , &eg[i].x , &eg[i].y , &eg[i].v) ;
            d[eg[i].x][eg[i].y] = d[eg[i].y][eg[i].x] = 1 ;
        }

        ///

        for (int k = 1 ; k <= n ; ++k)
            for (int i = 1 ; i <= n ; ++i)
                for (int j = 1 ; j <= n ; ++j)
                    d[i][j] = std::min(d[i][j] , d[i][k] + d[k][j]) ;

        for (int i = 1 ; i <= n ; ++i) {
            gt[i] = d[1][i] + d[i][n] ;
            que.push((data){gt[i] , i}) ;
        }
        for (; !que.empty() ;) {
            data x = que.top() ; que.pop() ;
            for (; !que.empty() && gt[x.idx] != x.val ; x = que.top() , que.pop()) ;
            if (gt[x.idx] != x.val) break ;

            for (int i = 1 ; i <= n ; ++i) {
                int nd = d[i][x.idx] + x.val ;
                if (nd < gt[i]) {
                    gt[i] = nd ;
                    que.push((data){gt[i] , i}) ;
                }
            } 
        }

        ///

        ll res = 1e15 ;
        for (int i = 0 ; i < m ; ++i) {
            Edge *pt = &eg[i] ;
            int p1 = std::min(gt[pt->x] , gt[pt->y]) + 2 ,
                p2 = std::min(d[1][pt->x] + d[pt->y][n] , d[1][pt->y] + d[pt->x][n]) + 1 ;
            res = std::min(res , std::min(p1 , p2) * (ll)pt->v) ;
        }
        printf("%lld\n" , res) ;
    }

    return 0 ;
}