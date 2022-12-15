#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

struct data {
    int val , idx ;
}a[MAX_N] ;

bool ap[MAX_N] ;
int T , n , b[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i) {
            scanf("%d" , &a[i].val) ;
            a[i].idx = i ; ap[i] = 0 ; b[i] = a[i].val ;
        }

        int ned = (1 << 30) - 1 ;
        std::vector<int> res ;
        for (; ;) {
            std::sort(a + 0 , a + n , [](data a , data b){
                return a.val > b.val ;
            }) ;

            int v = a[0].val , p = a[0].idx ;
            if (!v) break ;
            ap[p] = 1 ;
            res.push_back(p) ;

            ned -= v ;
            for (int i = 0 ; i < n ; ++i) a[i].val &= ned ;
        }

        for (int i = 0 ; i < n ; ++i) if (!ap[i]) res.push_back(i) ;
        for (auto &x : res) printf("%d " , b[x]) ;
        printf("\n") ;
    }

    return 0 ;
}