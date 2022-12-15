#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

struct data {int pl , a , L ;}dt[MAX_N << 1] ;

std::map<int , int> fr ;

int T , n , m , s[MAX_N << 1] ;

bool cmp(data p , data q) {return p.pl < q.pl || (p.pl == q.pl && p.a > q.a) ;}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        fr.clear() ;
        scanf("%d" , &n) ; m = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            int x , y ;
            scanf("%d %d" , &x , &y) ;
            dt[++m] = (data){x , 1 , x} ;
            dt[++m] = (data){y , -1 , x} ;
        }

        ///

        std::sort(dt + 1 , dt + 1 + m , cmp) ;
        for (int i = 1 ; i <= m ; ++i) {
            data *p = &dt[i] ;
            if (!fr.count(p->pl)) fr[p->pl] = i ;
        }

        s[0] = 0 ;
        for (int i = 1 ; i <= m ; ++i)
            if (dt[i].a > 0) s[i] = s[i - 1] ;
            else s[i] = s[i - 1] + 1 ;

        ///

        int nw = 0 , ans = 0 ;
        for (int i = 1 ; i <= m ; ++i) {
            data *p = &dt[i] ;
            int fir = fr[p->L] , tmp = nw + s[i - 1] - s[fir - 1] ;

            ans = std::max(ans , tmp) ;
            nw += p->a ;
        }

        printf("%d\n" , n - ans) ;
    }

    return 0 ;
}