#include <bits/stdc++.h>

const int MAX_N = 4e5 + 10 ;

struct data {
    int l , r , idx ;
} ;

data a[MAX_N] ;
int n , ans[MAX_N] ;

void work(int x , int y) {
    if (x == y) return ;
    int mid = (x + y) >> 1 ;
    work(x , mid) ; work(mid + 1 , y) ;

    std::vector<data> tmp ;
    int p1 = x , p2 = mid + 1 ;
    for (; p1 <= mid && p2 <= y ;)
        if (a[p1].r < a[p2].r) {
            tmp.push_back(a[p1]) ;
            ans[a[p1++].idx] += p2 - mid - 1 ;
        }
        else tmp.push_back(a[p2++]) ;
    for (; p1 <= mid ;) {
        tmp.push_back(a[p1]) ;
        ans[a[p1++].idx] += p2 - mid - 1 ;
    }
    for (; p2 <= y ;) tmp.push_back(a[p2++]) ;
    for (int i = x ; i <= y ; ++i) a[i] = tmp[i - x] ;
}

int main() {
    scanf("%d" , &n) ;
    for (int i = 0 ; i < n ; ++i) {
        auto &[l , r , idx] = a[i] ;
        scanf("%d %d" , &l , &r) ; idx = i ;
    }
    std::sort(a + 0 , a + n , [](const data &a , const data &b){
        return a.l < b.l ;
    }) ;

    work(0 , n - 1) ;
    for (int i = 0 ; i < n ; ++i) printf("%d\n" , ans[i]) ;

    return 0 ;
}