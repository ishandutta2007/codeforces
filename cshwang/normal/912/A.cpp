#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll A , B , x , y , z ;

int main() {
	scanf("%I64d %I64d" , &A , &B) ;
	scanf("%I64d %I64d %I64d" , &x , &y , &z) ;

	ll na = std::max(2 * x + y - A , (ll)0) , nb = std::max(y + 3 * z - B , (ll)0) ;

	printf("%I64d\n" , na + nb) ;

	return 0 ;
}