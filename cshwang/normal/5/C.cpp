#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 ;

struct data {short ty ; int p ;} ;

std::stack<data> sta ;

char s[MAX_N] ;
int n , mlen , cnt ;

int main() {
	scanf("%s" , s) ;
	n = strlen(s) ; mlen = 0 ; cnt = 1 ;

	sta.push((data){1 , -1}) ;
	for (int i = 0 ; i < n ; ++i)
		if (s[i] == '(') sta.push((data){0 , i}) ;
		else if (sta.top().ty == 1) sta.push((data){1 , i}) ;
		else {
			sta.pop() ;

			int len = i - sta.top().p ;
			if (len > mlen) mlen = len , cnt = 1 ;
			else if (len == mlen) ++cnt ;
		}

	printf("%d %d\n" , mlen , cnt) ;

	return 0 ;
}