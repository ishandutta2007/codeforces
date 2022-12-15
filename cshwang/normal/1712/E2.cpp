#include <bits/stdc++.h>

#define ll long long

const int N = 2e5 , MAX_N = N + 10 ;

struct data {
    int idx , r ;
} ;

std::vector<data> qry[MAX_N] ;

int T , c[MAX_N] ;
ll ans[MAX_N] , sum[MAX_N] , BIT[MAX_N] ;

ll cal(int x) {
    return ((ll)x * (x - 1)) >> 1 ;
}

ll cal_ex(int l , int r) {
    int nl = (5 * l + 1) >> 1 , s = 0 ;
    if (nl <= r) {
        int p1 = (nl + 14) / 15 , p2 = r / 15 ;
        s += p2 - p1 + 1 ;
    }

    nl = l << 1 ;
    if (nl <= r) {
        int p1 = (nl + 5) / 6 , p2 = r / 6 ;
        s += p2 - p1 + 1 ;
    }

    return s ;
}

inline int lowbit(int x) {return x & (-x) ;}

void add(int x , ll a) {
    for (; x <= N ; x += lowbit(x)) BIT[x] += a ;
}

ll getsum(int x) {
    ll s = 0 ;
    for (; x ; x -= lowbit(x)) s += BIT[x] ;
    return s ;
}

int main() {
    scanf("%d" , &T) ;
    for (int i = 0 ; i < T ; ++i) {
        int l , r ; scanf("%d %d" , &l , &r) ;
        qry[l].push_back((data){i , r}) ;
    }

    ///

    for (int i = 1 ; i <= N ; ++i)
        for (int j = i + i ; j <= N ; j += i) ++c[j] ;
    for (int i = 1 ; i <= N ; ++i) {
        add(i , cal(c[i])) ;
        sum[i] = sum[i - 1] + cal(i) ;
    }

    for (int i = 1 ; i <= N ; ++i) {
        for (auto &[idx , j] : qry[i]) {
            ll r = sum[j - i] - getsum(j) ;
            r -= cal_ex(i , j) ;

            ans[idx] = r ;
        }

        for (int j = i + i ; j <= N ; j += i) {
            int pre = cal(c[j]) , nxt = cal(--c[j]) ;
            add(j , nxt - pre) ;
        }
    }
    for (int i = 0 ; i < T ; ++i) printf("%lld\n" , ans[i]) ;

    return 0 ;
}