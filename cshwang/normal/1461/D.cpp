#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 ;

std::map<ll , int> ap ;

ll s[MAX_N] ;
int T , n , q , a[MAX_N] , pl[MAX_N] ;

int find(int x , int y , int num) {
	int L = x , R = y + 1 ;
	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;
		if (a[mid] <= num) L = mid ;
		else R = mid ;
	}

	return L ;
}

void work(int x , int y) {
	ap[s[y] - s[x - 1]] = 1 ;
	if (x == y || a[x] == a[y]) return ;

	int num = (a[x] + a[y]) >> 1 , pl = find(x , y , num) ;
	work(x , pl) ; work(pl + 1 , y) ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		ap.clear() ;

		scanf("%d %d" , &n , &q) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
		std::sort(a + 1 , a + n + 1) ;

		s[0] = 0 ;
		for (int i = 1 ; i <= n ; ++i) s[i] = s[i - 1] + a[i] ;

		///

		work(1 , n) ;
		for (; q-- ;) {
			int x ; scanf("%d" , &x) ;
			if (ap[x]) printf("Yes\n") ;
			else printf("No\n") ;
		}
	}

	return 0 ;
}