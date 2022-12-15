#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 3e5 + 10 , mod1 = 1e9 + 7 , mod2 = 1e9 + 9 ;

struct Hash {
    int h1 , h2 ;

    Hash operator +(const Hash &a) {
        return (Hash){
            h1 + a.h1 >= mod1 ? h1 + a.h1 - mod1 : h1 + a.h1 ,
            h2 + a.h2 >= mod2 ? h2 + a.h2 - mod2 : h2 + a.h2
        } ;
    }
    Hash operator -(const Hash &a) {
        return (Hash){
            h1 - a.h1 < 0 ? h1 - a.h1 + mod1 : h1 - a.h1 ,
            h2 - a.h2 < 0 ? h2 - a.h2 + mod2 : h2 - a.h2
        } ;
    }
    Hash operator *(int a) {
        return (Hash){(ll)h1 * a % mod1 , (ll)h2 * a % mod2} ;
    }
    Hash operator *(const Hash &a) {
        return (Hash){(ll)h1 * a.h1 % mod1 , (ll)h2 * a.h2 % mod2} ;
    }
    bool operator !=(const Hash &a) {
        return h1 != a.h1 || h2 != a.h2 ;
    }
}epy = Hash{0 , 0} , base[MAX_N] , ny[MAX_N] , BIT[2][MAX_N] ;

int n , a[MAX_N] ;

inline int lowbit(int x) {return x & (-x) ;}

void add(int op , int x) {
    Hash b = base[x] ;
    for (; x <= n ; x += lowbit(x)) BIT[op][x] = BIT[op][x] + b ;
}

Hash calc(int op , int x) {
    Hash sum = epy ;
    for (; x ; x -= lowbit(x)) sum = sum + BIT[op][x] ;
    return sum ;
}

bool check(int x) {
    int l = std::min(n - x , x - 1) + 1 ;
    Hash p1 = (calc(0 , x - 1) - calc(0 , x - l)) * ny[x - l] ;

    x = n + 1 - x ;
    Hash p2 = (calc(1 , x - 1) - calc(1 , x - l)) * ny[x - l] ;

    return p1 != p2 ;
}

int main() {
    scanf("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
    base[0] = (Hash){1 , 1} ; base[1] = (Hash){2 , 2} ;
    for (int i = 2 ; i <= n ; ++i) base[i] = base[i - 1] * base[1] ;
    ny[0] = (Hash){1 , 1} ; ny[1] = (Hash){(mod1 + 1) >> 1 , (mod2 + 1) >> 1} ;
    for (int i = 2 ; i <= n ; ++i) ny[i] = ny[i - 1] * ny[1] ;

    ///

    bool ok = 0 ;
    for (int i = 1 ; i <= n && !ok ; ++i) {
        int x = a[i] ;
        if (check(x)) ok = 1 ;
        add(0 , x) ;
        add(1 , n + 1 - x) ;
    }
    
    if (ok) printf("YES\n") ;
    else printf("NO\n") ;

    return 0 ;
}