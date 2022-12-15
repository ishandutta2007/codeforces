#include <bits/stdc++.h>

#define ll long long

const int N = 1e9 , MAX_N = 4e5 + 10 ;

struct data {
    int l , r , idx ;
} ;
struct Node {
    ll num ; int lazy ;
    void init() {num = lazy = 0 ;}
}tre[MAX_N << 2] ;

std::vector<int> idx ;
std::map<int , int> bh ;
std::vector<data> dt[MAX_N] ;

int T , n , tot , ans[MAX_N] , val[MAX_N] ;

void build(int t , int x , int y) {
    tre[t].init() ;
    if (x == y) return ;

    int mid = (x + y) >> 1 ;
    build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
}

void down(int t , int x , int y) {
    int v = tre[t].lazy ;
    if (!v) return ;

    tre[t].lazy = 0 ;
    int mid = (x + y) >> 1 ;
    tre[t << 1].num += (ll)v * (mid - x + 1) ; tre[t << 1].lazy += v ;
    tre[t << 1 | 1].num += (ll)v * (y - mid) ; tre[t << 1 | 1].lazy += v ;
}

void add(int t , int x , int y , int fx , int fy , int a) {
    if (y < fx || fy < x) return ;
    if (fx <= x && y <= fy) {
        tre[t].num += (y - x + 1) * a ;
        tre[t].lazy += a ;
        return ;
    }
    down(t , x , y) ;

    int mid = (x + y) >> 1 ;
    add(t << 1 , x , mid , fx , fy , a) ; add(t << 1 | 1 , mid + 1 , y , fx , fy , a) ;
    tre[t].num = tre[t << 1].num + tre[t << 1 | 1].num ;
}

ll calc(int t , int x , int y , int fx , int fy) {
    if (y < fx || fy < x) return 0 ;
    if (fx <= x && y <= fy) return tre[t].num ;
    down(t , x , y) ;

    int mid = (x + y) >> 1 ;
    return calc(t << 1 , x , mid , fx , fy) + calc(t << 1 | 1 , mid + 1 , y , fx , fy) ;
}

int findmax(int t , int x , int y , int fx , int fy) {
    if (y < fx || fy < x) return -N ;
    if (!tre[t].num) return -N ;
    if (x == y) return val[x] ;
    down(t , x , y) ;

    int mid = (x + y) >> 1 ;
    int p = findmax(t << 1 | 1 , mid + 1 , y , fx , fy) ;
    if (p == -N) return findmax(t << 1 , x , mid , fx , fy) ;
    else return p ;
}

int findmin(int t , int x , int y , int fx , int fy) {
    if (y < fx || fy < x) return (N << 1) ;
    if (!tre[t].num) return (N << 1) ;
    if (x == y) return val[x] ;
    down(t , x , y) ;

    int mid = (x + y) >> 1 ;
    int p = findmin(t << 1 , x , mid , fx , fy) ;
    if (p == (N << 1)) return findmin(t << 1 | 1 , mid + 1 , y , fx , fy) ;
    else return p ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ; idx.clear() ;
        for (int i = 1 ; i <= n ; ++i) dt[i].clear() ;

        for (int i = 1 ; i <= n ; ++i) {
            int l , r , c ;
            scanf("%d %d %d" , &l , &r , &c) ;
            dt[c].push_back((data){l , r , i}) ;
            idx.push_back(l) ; idx.push_back(r) ;
        }
        
        bh.clear() ; tot = 0 ;
        std::sort(idx.begin() , idx.end()) ;
        for (auto &x : idx)
            if (!bh.count(x)) {
                ++tot ;
                bh[x] = tot ;
                val[tot] = x ;
            }

        ///

        build(1 , 1 , tot) ;
        for (int i = 1 ; i <= n ; ++i)
            for (auto &x : dt[i]) add(1 , 1 , tot , bh[x.l] , bh[x.r] , 1) ;

        for (int i = 1 ; i <= n ; ++i) {
            for (auto &x : dt[i]) add(1 , 1 , tot , bh[x.l] , bh[x.r] , -1) ;
            for (auto &x : dt[i]) {
                int pl = bh[x.l] , pr = bh[x.r] ;
                if (calc(1 , 1 , tot , pl , pr) > 0) ans[x.idx] = 0 ;
                else {
                    int p1 = findmax(1 , 1 , tot , 1 , pl) ,
                        p2 = findmin(1 , 1 , tot , pr , N) ;
                    ans[x.idx] = std::min(x.l - p1 , p2 - x.r) ;
                }
            }
            for (auto &x : dt[i]) add(1 , 1 , tot , bh[x.l] , bh[x.r] , 1) ;
        }

        for (int i = 1 ; i <= n ; ++i) printf("%d " , ans[i]) ;
        printf("\n") ;
    }

    return 0 ;
}