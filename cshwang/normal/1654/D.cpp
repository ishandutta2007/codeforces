#include <bits/stdc++.h>

#define ll long long

const int N = 2e5 , MAX_N = 2e5 + 10 , mod = 998244353 ;

struct Link {
    int num , x , y ;
    Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
int T , n , cur , res , pri[MAX_N] , maxp[MAX_N] , cnt[MAX_N] ;

int gcd(int x , int y) {return y ? gcd(y , x % y) : x ;}

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    
    return s ;
}

void ins(int x , int y , int p , int q) {
    list[cur].num = y ;
    list[cur].x = p ;
    list[cur].y = q ;
    list[cur].next = head[x] ;
    head[x] = &list[cur++] ;
}

void add(int num , int ad) {
    for (; num > 1 ;) {
        int p = pri[num] ;
        cnt[p] += ad ;
        maxp[p] = std::max(maxp[p] , cnt[p]) ;
        num /= p ;
    }
}

void dfs(int x , int f) {
    for (Link *h = head[x] ; h ; h = h->next) {
        int nx = h->num ;
        if (nx == f) continue ;

        add(h->x , 1) ; add(h->y , -1) ;
        dfs(nx , x) ;
        add(h->x , -1) ; add(h->y , 1) ;
    }
}

void calc(int x , int f , int num) {
    (res += num) %= mod ;
    for (Link *h = head[x] ; h ; h = h->next) {
        int nx = h->num ;
        if (nx == f) continue ;

        int tmp = (ll)num * h->y % mod ;
        tmp = (ll)tmp * qpow(h->x , mod - 2) % mod ;
        calc(nx , x , tmp) ;
    }
}

int main() {
    scanf("%d" , &T) ;
    for (int i = 2 ; i <= N ; ++i)
        if (!pri[i]) for (int j = i ; j <= N ; j += i) if (!pri[j]) pri[j] = i ;
    
    for (; T-- ;) {
        scanf("%d" , &n) ;
        cur = 0 ;
        for (int i = 1 ; i <= n ; ++i) head[i] = NULL ;

        for (int i = 1 ; i < n ; ++i) {
            int x , y , p , q , d ;
            scanf("%d %d %d %d" , &x , &y , &p , &q) ;

            d = gcd(p , q) ; p /= d ; q /= d ;
            ins(x , y , p , q) ; ins(y , x , q , p) ;
        }

        ///

        for (int i = 0 ; i <= n ; ++i) maxp[i] = 0 ;
        dfs(1 , 1) ;

        res = 0 ; int num = 1 ;
        for (int i = 1 ; i <= n ; ++i)
            num = (ll)num * qpow(i , maxp[i]) % mod ;
        calc(1 , 1 , num) ;

        printf("%d\n" , res) ;
    }

    return 0 ;
}