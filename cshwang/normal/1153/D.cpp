#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N] ;

bool son[MAX_N] ;
Link *head[MAX_N] ;
int n , k , cur , f[MAX_N] , ty[MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dp(int x) {
	if (!head[x]) {
		f[x] = 1 ;
		return ;
	}

	int sum = -1 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		dp(nx) ;

		if (ty[x]) {
			if (sum == -1) sum = f[nx] ;
			else sum = std::min(sum , f[nx]) ;
		}
		else {
			if (sum == -1) sum = f[nx] ;
			else sum += f[nx] ;
		}
	}
	f[x] = sum ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &ty[i]) ;
	for (int i = 2 ; i <= n ; ++i) {
		int f ; scanf("%d" , &f) ;
		ins(f , i) ; son[f] = 1 ;
	}	

	k = 0 ;
	for (int i = 1 ; i <= n ; ++i) if (!son[i]) ++k ;

	///

	dp(1) ;
	printf("%d\n" , k - f[1] + 1) ;

	return 0 ;
}