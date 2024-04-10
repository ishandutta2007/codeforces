#include <bits/stdc++.h>

const int MAX_N = 100 + 10 ;

int T , n , a , f[MAX_N][MAX_N][2] ;

int merge_min(int s1 , int s2) {
    if (s1 == -1) return s2 ;
    if (s2 == -1) return s1 ;
    return std::min(s1 , s2) ;
}

int merge_max(int s1 , int s2) {
    if (s1 == -1) return s2 ;
    if (s2 == -1) return s1 ;
    return std::max(s1 , s2) ;
}

int work(int x , int y , int s) {
    if (x < 0 || y < 0) return -1 ;
    if (x + y == 1) {
        if (y) s ^= 1 ;
        if (s) return 0 ;
        else return 1 ;
    }
    if (!x && !y) {
        if (s) return 0 ;
        else return 1 ;
    }
    if (f[x][y][s] != -1) return f[x][y][s] ;

    int s1 = merge_min(work(x - 1 , y - 1 , s) , work(x - 2 , y , s)) ,
        s2 = merge_min(work(x - 1 , y - 1 , s ^ 1) , work(x , y - 2 , s ^ 1)) ;
    f[x][y][s] = merge_max(s1 , s2) ;
    return f[x][y][s] ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        int c1 = 0 , c0 = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            int v ; scanf("%d" , &v) ;
            if (v & 1) ++c1 ;
            else ++c0 ;
        }
        for (int i = 0 ; i <= c0 ; ++i)
            for (int j = 0 ; j <= c1 ; ++j) f[i][j][0] = f[i][j][1] = -1 ;
        
        if (work(c0 , c1 , 0)) printf("Alice\n") ;
        else printf("Bob\n") ;
    }

    return 0 ;
}