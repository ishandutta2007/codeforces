#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct data {int x , y ; ll c ;}list[MAX_N] ;

int n , len ;
char s[MAX_N] ;

bool cmp(data a , data b) {
	return (ll)a.x * b.y > (ll)a.y * b.x ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s) ;
		len = strlen(s) ;

		data *p = &list[i] ; ll cnt = 0 ;
		for (int j = len - 1 ; j >= 0 ; --j)
			if (s[j] == 'h') ++cnt ;
			else p->c += cnt ;

		p->x = len - cnt ; p->y = cnt ;
	}

	///

	std::sort(list + 0 , list + n , cmp) ;

	ll ans = 0 , cnt = 0 ;
	for (int i = n - 1 ; i >= 0 ; --i) {
		data *p = &list[i] ;
		ans += p->x * cnt ;
		ans += p->c ;

		cnt += p->y ;
	}

	printf("%I64d\n" , ans) ;

	return 0 ;
}