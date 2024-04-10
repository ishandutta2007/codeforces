#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int N = 1 << 15 , MAX_N = 2e5 + 10 , MAX_M = (1 << 16) + 5 ;

char s[MAX_N] ;
ll ans , a[MAX_N] ;
int n , m , p , mc , b[MAX_N] , cnt[MAX_M] , f[MAX_M] ;

inline ll lowbit(ll x) {return x & (-x) ;}

int count(int x) {
	int s = 0 ;
	for (; x ; x -= lowbit(x)) ++s ;

	return s ;
}

ll trans() {
	ll nw = 1 , sum = 0 ;
	for (int i = 0 ; i < m ; ++i , nw <<= 1)
		if (s[i] == '1') sum += nw ;

	return sum ;
}

void check(ll S) {
	for (int i = 1 ; i <= n ; ++i) b[i] = 0 ;
	for (int i = 0 ; i < N ; ++i) f[i] = 0 ;

	///

	int tot = 0 , TN = 0 ;
	for (ll nS = S ; nS ; nS -= lowbit(nS) , ++tot) {
		ll nw = lowbit(nS) ;
		for (int i = 1 ; i <= n ; ++i) if (nw & a[i]) b[i] |= (1 << tot) ;
	}

	TN = 1 << tot ;
	for (int i = 1 ; i <= n ; ++i) ++f[b[i]] ;
	for (int i = 0 ; i < TN ; ++i)
		for (int j = (i - 1) & i ; j ; j = (j - 1) & i) f[j] += f[i] ;

	///

	int nw = 0 , c = -1 , ned = (n + 1) >> 1 ;
	for (int i = 0 ; i < TN ; ++i)
		if (f[i] >= ned && cnt[i] > c) {c = cnt[i] ; nw = i ;}

	ll res = 0 ; tot = 0 ;
	for (ll nS = S ; nS ; nS -= lowbit(nS) , ++tot)
		if (nw & (1 << tot)) res += lowbit(nS) ;

	if (c > mc) {mc = c ; ans = res ;}
}

int main() {
    srand(19260817) ;
    
	scanf("%d %d %d" , &n , &m , &p) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%s" , s) ;
		a[i] = trans() ;
	}

	///

	std::random_shuffle(a + 1 , a + 1 + n) ;
	for (int i = 0 ; i < N ; ++i) cnt[i] = count(i) ;

	///

	mc = 0 ;
	int ed = std::min(n , 8) ;
	for (int i = 1 ; i <= ed ; ++i) check(a[i]) ;

	for (int i = 0 ; i < m ; ++i)
		if (ans & (1LL << i)) printf("1") ;
		else printf("0") ;
	printf("\n") ;

	return 0 ;
}