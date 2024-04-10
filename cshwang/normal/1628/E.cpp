#include <bits/stdc++.h>

const int MAX_N = 6e5 + 10 , lgN = 20 + 5 , INF = 0x3f3f3f3f ;

typedef std::pair<int , int> pir ;
typedef std::tuple<int , int , int> tup ;

struct data {
    int ty ;
    pir nmin , nmax , mind , maxd ;
}tre[MAX_N << 2] ;

int n , m , q , ti , mlg , val[MAX_N] , fa[MAX_N] , dfn[MAX_N] , dep[MAX_N] , ch[2][MAX_N] , f[lgN][MAX_N] ;

int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

void dfs(int x , int prev) {
    dfn[x] = ++ti ; f[0][x] = prev ;
    if (x <= n) return ;

    dep[ch[0][x]] = dep[x] + 1 ;
    dep[ch[1][x]] = dep[x] + 1 ;
    dfs(ch[0][x] , x) ; dfs(ch[1][x] , x) ;
}

void build(int t , int x , int y) {
    tre[t].ty = 0 ;
    if (x == y) {
        tre[t].mind = tre[t].maxd = std::make_pair(dfn[x] , x) ;
        tre[t].nmin = std::make_pair(INF , -1) ; tre[t].nmax = std::make_pair(-INF , -1) ;
        return ;
    }

    int mid = (x + y) >> 1 ;
    build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
    tre[t].mind = std::min(tre[t << 1].mind , tre[t << 1 | 1].mind) ;
    tre[t].maxd = std::max(tre[t << 1].maxd , tre[t << 1 | 1].maxd) ;
    tre[t].nmin = std::min(tre[t << 1].nmin , tre[t << 1 | 1].nmin) ;
    tre[t].nmax = std::max(tre[t << 1].nmax , tre[t << 1 | 1].nmax) ;
}

void down(int t) {
    int a = tre[t].ty ;
    if (a == -1) return ;

    tre[t << 1].ty = tre[t << 1 | 1].ty = a ;
    if (a == 1) {
        for (int i = 0 ; i < 2 ; ++i)
            tre[t << 1 | i].nmin = tre[t << 1 | i].mind ,
            tre[t << 1 | i].nmax = tre[t << 1 | i].maxd ;
    }
    else {
        for (int i = 0 ; i < 2 ; ++i)
            tre[t << 1 | i].nmin = std::make_pair(INF , -1) ,
            tre[t << 1 | i].nmax = std::make_pair(-INF , -1) ;
    }
}

void modify(int t , int x , int y , int fx , int fy , int a) {
    if (y < fx || fy < x) return ;
    if (fx <= x && y <= fy && tre[t].ty != -1) {
        tre[t].ty = a ;
        if (a) {
            tre[t].nmin = tre[t].mind ;
            tre[t].nmax = tre[t].maxd ;
        }
        else {
            tre[t].nmin = std::make_pair(INF , -1) ;
            tre[t].nmax = std::make_pair(-INF , -1) ;
        }
        return ;
    }
    down(t) ;

    int mid = (x + y) >> 1 ;
    modify(t << 1 , x , mid , fx , fy , a) ;
    modify(t << 1 | 1 , mid + 1 , y , fx , fy , a) ;
    tre[t].nmin = std::min(tre[t << 1].nmin , tre[t << 1 | 1].nmin) ;
    tre[t].nmax = std::max(tre[t << 1].nmax , tre[t << 1 | 1].nmax) ;
    tre[t].ty = tre[t << 1].ty == tre[t << 1 | 1].ty ? tre[t << 1].ty : -1 ;
}

int lca(int x , int y) {
    if (dep[x] > dep[y]) std::swap(x , y) ;
    for (int i = mlg ; i >= 0 ; --i) {
        int u = f[i][y] ;
        if (dep[u] >= dep[x]) y = u ;
    }

    if (x == y) return x ;

    for (int i = mlg ; i >= 0 ; --i) {
        int u = f[i][x] , v = f[i][y] ;
        if (u != v) x = u , y = v ;
    }
    return f[0][x] ;
}

int main() {
    std::vector<tup> eg ;
    scanf("%d %d" , &n , &q) ; m = n << 1 ;
    for (int i = 1 ; i < n ; ++i) {
        int u , v , w ; scanf("%d %d %d" , &u , &v , &w) ;
        eg.push_back(std::make_tuple(w , u , v)) ;
    }
    std::sort(eg.begin() , eg.end()) ;

    for (int i = 1 ; i < m ; ++i) fa[i] = val[i] = -1 ;
    for (int i = 0 ; i < n - 1 ; ++i) {
        int idx = i + 1 + n ;
        auto [w , u , v] = eg[i] ;

        ch[0][idx] = (u = findset(u)) ;
        ch[1][idx] = (v = findset(v)) ;
        fa[u] = fa[v] = idx ; val[idx] = w ;
    }
    
    ///

    dfs(m - 1 , m - 1) ;
    build(1 , 1 , n) ;

    mlg = 31 - __builtin_clz(m) ;
    for (int i = 1 ; i <= mlg ; ++i)
        for (int j = 1 ; j < m ; ++j) f[i][j] = f[i - 1][f[i - 1][j]] ;
    
    for (; q-- ;) {
        int op , l , r ;
        scanf("%d %d" , &op , &l) ;
        if (op != 3) scanf("%d" , &r) ;
        if (op == 1) modify(1 , 1 , n , l , r , 1) ;
        else if (op == 2) modify(1 , 1 , n , l , r , 0) ;
        else {
            int u = tre[1].nmin.second , v = tre[1].nmax.second ;
            if (u == -1 || v == -1) printf("-1\n") ;
            else {
                u = lca(lca(u , v) , l) ;
                printf("%d\n" , val[u]) ;
            }
        }
    }

    return 0 ;
}