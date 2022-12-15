#include <bits/stdc++.h>

typedef std::pair<int , int> pir ;

int T , n ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        std::vector<pir> res ;

        int m = n * 3 , len = m ;
        for (int i = 1 ; i <= len ; i += 3) {
            if (i >= m) break ;

            res.push_back(std::make_pair(i , m)) ;
            m -= 3 ;
        }

        printf("%d\n" , res.size()) ;
        for (auto &x : res) printf("%d %d\n" , x.first , x.second) ;
    }

    return 0 ;
}