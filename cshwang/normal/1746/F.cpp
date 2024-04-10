#include <bits/stdc++.h>

#define ull unsigned long long

const int B = 60 , MAX_N = 3e5 + 10 , MAX_B = 60 + 5 ;

std::map<int , ull> idx ;
std::mt19937_64 rng(std::chrono::steady_clock().now().time_since_epoch().count()) ;

int n , q , val[MAX_N] , BIT[MAX_B][MAX_N] ;

ull rd(ull l = 1 , ull r = (1ll << 60) - 1) {
    std::uniform_int_distribution<ull> u(l , r) ;
    return u(rng) ;
}

inline int lowbit(int x) {return x & (-x) ;}

void addBIT(int x , int y , int a) {
    for (; y <= n ; y += lowbit(y)) BIT[x][y] += a ;
}

int calc(int x , int y) {
    int s = 0 ;
    for (; y ; y -= lowbit(y)) s += BIT[x][y] ;
    return s ;
}

void add(int v , int x , int a) {
    if (!idx.count(v)) idx[v] = rd() ;
    v = idx[v] ;

    for (int i = 0 ; i < B ; ++i)
        if (v >> i & 1) addBIT(i , x , a) ;
}

int main() {
    scanf("%d %d" , &n , &q) ;
    for (int i = 1 ; i <= n ; ++i) {
        int v ; scanf("%d" , &v) ;
        add(v , i , 1) ; val[i] = v ;
    }

    ///

    for (; q-- ;) {
        int op , x , y ;
        scanf("%d %d %d" , &op , &x , &y) ;
        if (op == 1) {
            add(val[x] , x , -1) ;
            add(y , x , 1) ;
            val[x] = y ;
        }
        else {
            int k ; scanf("%d" , &k) ;

            bool ok = 1 ;
            for (int i = 0 ; i < B ; ++i)
                if (calc(i , y) % k != calc(i , x - 1) % k) ok = 0 ;
            if (ok) printf("YES\n") ;
            else printf("NO\n") ;
        }
    }

    return 0 ;
}