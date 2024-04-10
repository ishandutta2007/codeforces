#include <bits/stdc++.h>
using namespace std ;

int T , n ;

set<string> st[4] ;

bool check(int x , string y) {
    return st[x].find(y) != st[x].end() ;
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;

    cin >> T ;
    for (; T-- ;) {
        cin >> n ; bool ok = 0 ;
        for (int i = 1 ; i <= 3 ; ++i) st[i].clear() ;

        for (int i = 0 ; i < n ; ++i) {
            string x ; cin >> x ;
            ok |= x.size() == 1 ;

            if (x.size() == 3) {
                string a[2] = {x.substr(1 , 2) , x} ;
                for (auto &y : a) std::reverse(y.begin() , y.end()) ;
                ok |= check(2 , a[0]) || x == a[1] || check(3 , a[1]) ;
                st[1].insert(x.substr(0 , 2)) ;
            }
            if (x.size() == 2) {
                string a = x ;
                reverse(a.begin() , a.end()) ;
                ok |= check(2 , a) || check(1 , a) || x == a ;
            }
            st[x.size()].insert(x) ;
        }

        ///

        if (ok) cout << "YES\n" ;
        else cout << "NO\n" ;
    }

    return 0 ;
}