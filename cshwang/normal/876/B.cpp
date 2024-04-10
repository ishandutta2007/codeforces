#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 ;

struct data {
	int num ;
	data *next ;
}list[MAX_N] ;

data *head[MAX_N] ;
int n , m , k , cur , cnt[MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	scanf("%d %d %d" , &n , &m , &k) ;
	for (int i = 0 ; i < n ; ++i) {
		int a , b ; scanf("%d" , &a) ;
		b = a % k ;
		ins(b , a) ; ++cnt[b] ;
	}

	///

	bool ok = 0 ;
	for (int i = 0 ; i < k && (!ok) ; ++i)
		if (cnt[i] >= m) {
			printf("Yes\n") ;
			data *h = head[i] ;
			for (int j = 0 ; j < m ; ++j , h = h->next) printf("%d " , h->num) ;
			printf("\n") ;

			ok = 1 ;
		}
	if (!ok) printf("No\n") ;

	return 0 ;
}