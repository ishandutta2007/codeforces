#include <bits/stdc++.h>

const int M = 20 , MAX_N = 5e5 + 10 , MAX_M = M + 5 ;

struct Space {
    struct data {
        int val , idx ;
        data operator ^(const data &b) {
            return (data){val ^ b.val , idx} ;
        }
        int& operator [](int x) {
            if (!x) return val ;
            return idx ;
        }
    } ;

    data vec[MAX_M] ;
    void init() {
        for (int i = 0 ; i <= M ; ++i) vec[i][0] = 0 ;
    }
    void add(data x) {
        for (int i = M ; i >= 0 ; --i)
            if (x[0] >> i & 1) {
                if (vec[i][0]) {
                    if (vec[i][1] < x[1]) std::swap(vec[i] , x) ;
                    x = x ^ vec[i] ;
                }
                else {vec[i] = x ; break ;}
            }
    }
    int maxvec(int x) {
        int s = 0 ;
        for (int i = M ; i >= 0 ; --i)
            if (vec[i][1] >= x) s ^= (s >> i & 1) ? 0 : vec[i][0] ;
        return s ;
    }
}sp[MAX_N] ;

int n , q ;

int main() {
    sp[0].init() ; scanf("%d" , &n) ;
    for (int i = 1 ; i <= n ; ++i) {
        int x ; scanf("%d" , &x) ;
        sp[i] = sp[i - 1] ; sp[i].add({x , i}) ;
    }
    scanf("%d" , &q) ;
    for (; q-- ;) {
        int x , y ; scanf("%d %d" , &x , &y) ;
        printf("%d\n" , sp[y].maxvec(x)) ;
    }

    return 0 ;
}