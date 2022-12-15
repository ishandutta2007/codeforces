#include <bits/stdc++.h>

typedef long long ll ;

const int MAX_N = 3e5 + 10 ;

struct data {
    int num , ty , idx ;
}ant[MAX_N] ;

ll t ;
int n , m , ans[MAX_N] , b[MAX_N] ;

int main() {
    scanf("%d %d %lld" , &n , &m , &t) ;
    for (int i = 0 ; i < n ; ++i) {
        int x ; char op ;
        scanf("%d %c" , &x , &op) ; --x ;

        if (op == 'L') ant[i] = (data){x , 0 , i} ;
        else ant[i] = (data){x , 1 , i} ;
    }

    ///

    std::sort(ant + 0 , ant + n , [](const data &a , const data &b){
        return a.num < b.num ;
    }) ;

    ll id = 0 ;
    for (int i = 0 ; i < n ; ++i) {
        if (ant[i].ty == 0) {
            ll delt = t - ant[i].num ;
            delt = delt >= 0 ? (delt + m - 1) / m : 0 ;
            id = ((id - delt) % n + n) % n ;
            b[i] = ((ant[i].num - t) % m + m) % m ;
        }
        else {
            ll delt = t - (m - 1 - ant[i].num) ;
            delt = delt > 0 ? (delt + m - 1) / m : 0 ;
            id = (id + delt) % n ;
            b[i] = (ant[i].num + t) % m ;
        }
    }

    std::sort(b + 0 , b + n) ;
    for (int i = 0 ; i < n ; ++i , (++id) %= n) ans[ant[i].idx] = b[id] ;
    for (int i = 0 ; i < n ; ++i) printf("%d " , ans[i] + 1) ;

    return 0 ;
}