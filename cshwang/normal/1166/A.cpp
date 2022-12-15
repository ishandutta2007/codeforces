#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

char s[MAX_N] ;
int cnt['z' + 10] ;

inline int count(int x) {return (x * (x - 1)) >> 1 ;}

int main() {
	int n ; scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s) ;
		++cnt[s[0]] ;
	}

	int ans = 0 ;
	for (int i = 'a' ; i <= 'z' ; ++i) {
		int t = cnt[i] ;
		if (t <= 1) continue ;

		int p1 = t / 2 , p2 = t - p1 ;
		ans += count(p1) + count(p2) ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}