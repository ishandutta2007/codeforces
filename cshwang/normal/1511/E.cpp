#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 , mod = 998244353 ;

std::vector<char> s[MAX_N] ;

char tmp[MAX_N] ;
int n , m , tot , f[MAX_N] , pw2[MAX_N] ;

void init() {
	int N = n * m ;

	pw2[0] = 1 ;
	for (int i = 1 ; i <= N ; ++i) pw2[i] = (pw2[i - 1] << 1) % mod ;

	int g = 0 , sum = 0 ;
	f[0] = f[1] = 0 ;
	for (int i = 2 ; i <= N ; ++i) {
		(g <<= 1) %= mod ; (g += ((i - 1) >> 1)) %= mod ;
		f[i] = ((ll)sum + g + (i >> 1)) % mod ;
		(sum += f[i]) %= mod ;
	}
}

int work(int n) {
	int c = 0 , sum = 0 ;

	tmp[n] = '*' ;
	for (int i = 0 ; i <= n ; ++i)
		if (tmp[i] == 'o') ++c ;
		else {
			int p1 = f[c] , p2 = tot - c ;
			p1 = (ll)p1 * pw2[p2] % mod ;
			(sum += p1) %= mod ;
			c = 0 ;
		}

	return sum ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , tmp) ;
		for (int j = 0 ; j < m ; ++j) {
			s[i].push_back(tmp[j]) ;
			if (tmp[j] == 'o') ++tot ;
		}
	}

	///

	init() ;

	int ans = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < m ; ++j) tmp[j] = s[i][j] ;
		(ans += work(m)) %= mod ;
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) tmp[j] = s[j][i] ;
		(ans += work(n)) %= mod ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}