#include <stack>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 , MAX_M = 1e7 + 10 ;

std::stack<int> sta ;

bool ap[MAX_M] ;
int T , n , k , tot , pri[MAX_M] , fir[MAX_M] , cnt[MAX_M] ;

void init() {
	int n = 1e7 ;
	for (int i = 2 ; i <= n ; ++i) {
		if (!ap[i]) {pri[tot++] = i ; fir[i] = i ;}

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * pri[j] ;
			if (tmp > n) break ;
			ap[tmp] = 1 ; fir[tmp] = pri[j] ;

			if (!(i % pri[j])) break ;
		}
	}
}

int work(int x) {
	int s = 1 ;
	for (; x > 1 ;) {
		int a = fir[x] , c = 0 ;
		for (; fir[x] == a ; x /= a , ++c) ;

		if (c & 1) s *= a ;
	}

	return s ;
}

int main() {
	init() ;

	scanf("%d" , &T) ;
	for (; T-- ;) {
		int ans = 1 ;
		scanf("%d %d" , &n , &k) ;
		for (int i = 0 ; i < n ; ++i) {
			int t ;
			scanf("%d" , &t) ;
			t = work(t) ;

			///

			if (cnt[t]) {
				++ans ;
				for (; !sta.empty() ;) {--cnt[sta.top()] ; sta.pop() ;}
			}
			sta.push(t) ; ++cnt[t] ;
		}

		///

		for (; !sta.empty() ;) {--cnt[sta.top()] ; sta.pop() ;}
		printf("%d\n" , ans) ;
	}

	return 0 ;
}