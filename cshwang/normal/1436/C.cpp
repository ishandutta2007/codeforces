#include <stdio.h>
#include <stdlib.h> 

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int mod = 1e9 + 7 ;

int n , num , pos , ans ;

void find(int x , int y , int les , int mor) {
	if (pos < x - 1 || y < pos) return ;
	if (x >= y) {
		if (y - 1 != pos) return ;

		ans = 1 ;
		int tot = n - num ;
		for (int i = 0 ; i < mor ; ++i , --tot) ans = (ll)ans * tot % mod ;
		tot = num - 1 ;
		for (int i = 0 ; i < les ; ++i , --tot) ans = (ll)ans * tot % mod ;
		tot = n - les - mor - 1 ;
		for (int i = tot ; i ; --i) ans = (ll)ans * i % mod ;

		return ;
	}

	int mid = (x + y) >> 1 ;
	if (mid != pos) find(x , mid , les , mor + 1) , find(mid + 1 , y , les + 1 , mor) ;
	else find(mid + 1 , y , les , mor) ;
}

int main() {
	scanf("%d %d %d" , &n , &num , &pos) ;
	ans = 0 ; find(0 , n , 0 , 0) ;

	printf("%d\n" , ans) ;

	return 0 ;
}