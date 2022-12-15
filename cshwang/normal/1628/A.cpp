#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

std::queue<int> que[MAX_N] ;

int T , n ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i <= n ; ++i)
            for (; !que[i].empty() ; que[i].pop()) ;
        for (int i = 1 ; i <= n ; ++i) {
            int x ; scanf("%d" , &x) ;
            que[x].push(i) ;
        }

        std::vector<int> ans ;
        for (int L = 1 , R = n ; L <= n ;) {
            int idx = L , x ;
            for (x = 0 ; ; ++x) {
                for (; !que[x].empty() && que[x].front() < L ; que[x].pop()) ;
                if (que[x].empty()) break ;
                idx = std::max(idx , que[x].front()) ;
            }
            ans.push_back(x) ; L = idx + 1 ;
        }

        printf("%d\n" , (int)ans.size()) ;
        for (auto &x : ans) printf("%d " , x) ;
        printf("\n") ;
    }

    return 0 ;
}