#include <bits/stdc++.h>

#define ll long long
#define pir std::pair<int , int>

const int MAX_N = 1e3 + 10 ;

struct Point {
    int x , y ;

    friend Point operator +(Point a , Point b) {
        return (Point){a.x + b.x , a.y + b.y} ;
    }
    friend Point operator -(Point a , Point b) {
        return (Point){a.x - b.x , a.y - b.y} ;
    }
    friend Point operator -(Point a) {
        return (Point){-a.x , -a.y} ;
    }
    friend Point operator *(Point a , int d) {
        return (Point){a.x * d , a.y * d} ;
    }
    friend Point operator /(Point a , int d) {
        return (Point){a.x / d , a.y / d} ;
    }
    friend bool operator ==(Point a , Point b) {
        return a.x == b.x && a.y == b.y ;
    }
    friend bool operator !=(Point a , Point b) {
        return !(a == b) ;
    }
    friend bool operator <(Point a , Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y) ;
    }
    friend bool operator >(Point a , Point b) {
        return (a.x > b.x) || (a.x == b.x && a.y > b.y) ;
    }
} ;
struct data {
    bool rv ;
    Point a , b , k ;
}a[MAX_N] ;

std::map<pir , int> cnt ;

int n , maxk[MAX_N] , ap[MAX_N * MAX_N] ;

Point calc(Point b , Point a) {
    if (b < a) std::swap(a , b) ;

    Point k = b - a ;
    int d = std::__gcd(abs(k.x) , abs(k.y)) ;
    k = k / d ;
    return k ;
}

inline ll det(Point a , Point b) {return (ll)a.x * b.y - (ll)a.y * b.x ;}

int main() {
    scanf("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i) ap[i * (i - 1)] = i ;
    for (int i = 0 ; i < n ; ++i) {
        a[i].rv = 0 ;
        scanf("%d %d %d %d" , &a[i].a.x , &a[i].a.y , &a[i].b.x , &a[i].b.y) ;
        if (a[i].a > a[i].b) std::swap(a[i].a , a[i].b) ;
        a[i].k = calc(a[i].b , a[i].a) ;
    }

    for (int i = 0 ; i < n ; ++i)
        for (int j = i + 1 ; j < n ; ++j)
            if (a[i].k == a[j].k) {
                Point p1 = calc(a[i].a , a[j].a) ;
                if (p1 != a[i].k) continue ;
                else if (a[i].b < a[j].a || a[j].b < a[i].a) continue ;
                else {
                    a[j].a = std::min(a[i].a , a[j].a) ;
                    a[j].b = std::max(a[i].b , a[j].b) ;
                    a[i].rv = 1 ;
                    break ;
                }
            }
            else {
                Point c = a[j].a - a[i].a , p = a[i].k , q = -a[j].k ;
                int maxk1 , maxk2 ;
                if (a[i].k.x) maxk1 = (a[i].b - a[i].a).x / a[i].k.x ;
                else maxk1 = (a[i].b - a[i].a).y / a[i].k.y ;
                if (a[j].k.x) maxk2 = (a[j].b - a[j].a).x / a[j].k.x ;
                else maxk2 = (a[j].b - a[j].a).y / a[j].k.y ;

                ll D = det(p , q) , D1 = det(c , q) , D2 = det(p , c) ;
                if (D1 % D || D2 % D) continue ;

                D1 /= D ; D2 /= D ;
                if (D1 > maxk1 || D2 > maxk2 || D1 < 0 || D2 < 0) continue ;
                Point tmp = a[i].a + a[i].k * int(D1) ;
                ++cnt[std::make_pair(tmp.x , tmp.y)] ;
            }
    
    int tot = 0 ;
    for (int i = 0 ; i < n ; ++i)
        if (!a[i].rv) {
            if (a[i].k.x) tot += (a[i].b - a[i].a).x / a[i].k.x + 1 ;
            else tot += (a[i].b - a[i].a).y / a[i].k.y + 1 ;
        }
    for (auto &[x , y] : cnt) tot -= (ap[y << 1] - 1) ;
    printf("%d\n" , tot) ;

    return 0 ;
}