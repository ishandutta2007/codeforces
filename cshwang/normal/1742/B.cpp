#include <bits/stdc++.h>

const int MAX_N = 100 + 10 ;

int T , n ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;

        std::set<int> st ;
        for (int i = 1 ; i <= n ; ++i) {
            int v ; scanf("%d" , &v) ;
            st.insert(v) ;
        }

        if (st.size() == n) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}