#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 , INF = 0x3f3f3f3f ;

struct data {int pl , sum ;} ;

std::vector<data> a[MAX_N] ;

char s[MAX_N] ;
int T , n , p , k , x , y ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d %d" , &n , &p , &k) ;
		scanf("%s" , s) ;
		scanf("%d %d" , &x , &y) ;

		///

		for (int i = n ; i ; --i) s[i] = s[i - 1] ;
		for (int i = 0 ; i < k ; ++i) a[i].clear() ;
		for (int i = p ; i <= n ; ++i) a[i % k].push_back((data){i , (s[i] == '1') ? 0 : 1}) ;

		///

		int ans = INF ;
		for (int i = 0 ; i < k ; ++i) {
			int m = a[i].size() ;
			for (int j = m - 1 ; j >= 0 ; --j) {
				if (j != m - 1) a[i][j].sum += a[i][j + 1].sum ;

				int tmp = a[i][j].sum * x + (a[i][j].pl - p) * y ;
				ans = std::min(ans , tmp) ;
			}
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}