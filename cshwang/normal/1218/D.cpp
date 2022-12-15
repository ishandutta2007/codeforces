#include <bits/stdc++.h>

#define ll long long

const int N = (1 << 17) , MAX_N = 2e5 + 10 , MAX_M = 100 + 5 , mod = 1e9 + 7 , mod2 = 1e9 + 9 ;

struct Edge {
    int x , y , v ;
}eg[MAX_N] ;
struct Link {
    int num , val ;
    Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
std::stack<int> sta ;
std::vector<int> eval[MAX_M] ;
int n , m , tot , cur , txor , ti , dfn[MAX_N] , low[MAX_N] , col[MAX_N] , f[2][MAX_N] , g[2][MAX_N] ;

void ins(int x , int y , int v) {
    list[cur].num = y ;
    list[cur].val = v ;
    list[cur].next = head[x] ;
    head[x] = &list[cur++] ;
}

void dfs(int x) {
    sta.push(x) ;
    dfn[x] = low[x] = ++ti ;
    for (Link *h = head[x] ; h ; h = h->next) {
        int nx = h->num ;
        if (!dfn[nx]) {
            dfs(nx) ;
            low[x] = std::min(low[x] , low[nx]) ;

            if (low[nx] == dfn[x]) {
                if (sta.top() == nx) sta.pop() ;
                else {
                    col[x] = ++tot ;
                    while (sta.top() != nx) {
                        col[sta.top()] = tot ;
                        sta.pop() ;
                    }
                    col[nx] = tot ; sta.pop() ;
                }
            }
        }
        else low[x] = std::min(low[x] , dfn[nx]) ;
    }
}

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

void DFT(int *F , int mod) {
    for (int L = 2 ; L <= N ; L <<= 1)
        for (int i = 0 ; i < N ; i += L) {
            int hf = L >> 1 ;
            for (int j = 0 ; j < hf ; ++j) {
                int t1 = F[i + j] + F[i + j + hf] , t2 = F[i + j] - F[i + j + hf] ;
                if (t1 >= mod) t1 -= mod ;
                if (t2 < 0) t2 += mod ;

                F[i + j] = t1 ; F[i + j + hf] = t2 ;
            }
        }
}

void IDFT(int *F , int mod) {
    int ny = qpow(2 , mod - 2) ;
    for (int L = 2 ; L <= N ; L <<= 1)
        for (int i = 0 ; i < N ; i += L) {
            int hf = L >> 1 ;
            for (int j = 0 ; j < hf ; ++j) {
                int t1 = F[i + j] + F[i + j + hf] , t2 = F[i + j] - F[i + j + hf] ;
                if (t1 >= mod) t1 -= mod ;
                if (t2 < 0) t2 += mod ;

                F[i + j] = (ll)t1 * ny % mod ; F[i + j + hf] = (ll)t2 * ny % mod ;
            }
        }
}

int main() {
    scanf("%d %d" , &n , &m) ;
    for (int i = 0 ; i < m ; ++i) {
        int x , y , v ;
        scanf("%d %d %d" , &x , &y , &v) ;
        ins(x , y , v) ; ins(y , x , v) ;
        eg[i] = (Edge){x , y , v} ; txor ^= v ;
    }

    ///

    dfs(1) ;
    for (int i = 0 ; i < m ; ++i) {
        Edge *pt = &eg[i] ;
        if (col[pt->x] == col[pt->y]) eval[col[pt->x]].push_back(pt->v) ;
    }

    int op = 1 ;
    f[0][0] = 1 ; g[0][0] = 1 ;
    DFT(f[0] , mod) ; DFT(g[0] , mod2) ;
    for (int i = 1 ; i <= tot ; ++i , op ^= 1) {
        for (int j = 0 ; j < N ; ++j) f[op][j] = g[op][j] = 0 ;
        for (auto &x : eval[i]) ++f[op][x] , ++g[op][x] ;
        DFT(f[op] , mod) ; DFT(g[op] , mod2) ;
        for (int j = 0 ; j < N ; ++j)
            f[op][j] = (ll)f[op][j] * f[op ^ 1][j] % mod ,
            g[op][j] = (ll)g[op][j] * g[op ^ 1][j] % mod2 ;
    }
    op ^= 1 ; IDFT(f[op] , mod) ; IDFT(g[op] , mod2) ;

    int mx = N + 1 , siz = 0 ;
    for (int i = 0 ; i < N ; ++i)
        if (f[op][i] || g[op][i]) {
            int tmp = i ^ txor ;
            if (tmp < mx) {mx = tmp ; siz = f[op][i] ;}
        }
    printf("%d %d\n" , mx , siz) ;

    return 0 ;
}