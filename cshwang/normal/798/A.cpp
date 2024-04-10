#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_N = 15 + 10 ;

char s[MAX_N] , L , R ;

int main()
{
	scanf("%s" , s) ;
	L = 0 ; R = strlen(s) - 1 ;

	int sum = 0 ;
	for (; L <= R ; ++L , --R)
	{
		if (s[L] != s[R]) ++sum ;
		if (L == R && !sum) ++sum ;
	}

	if (sum == 1) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}