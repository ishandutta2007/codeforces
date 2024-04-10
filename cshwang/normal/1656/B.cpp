#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

std::set<int> st ;

int T , n , k , a[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &k) ;

        st.clear() ;
        for (int i = 0 ; i < n ; ++i) {
            int a ; scanf("%d" , &a) ;
            st.insert(a) ;
        }

        ///

        bool ok = 0 ;
        for (auto x : st) {
            int nx = x + k ;
            if (st.count(nx) > 0) ok = 1 ;
        }

        if (ok) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}