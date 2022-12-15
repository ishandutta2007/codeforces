#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 50 + 10 , INF = 0x3f3f3f3f ;

int n , len ;
char s[MAX_N][MAX_N] , ns[MAX_N] ;

void down(char *s)
{
	char top = s[0] ;
	for (int i = 1 ; i < len ; ++i) std::swap(s[i - 1] , s[i]) ;

	s[len - 1] = top ;
}

bool cmp(char *s1 , char *s2)
{
	for (int i = 0 ; i < len ; ++i)
		if (s1[i] != s2[i]) return 0 ;

	return 1 ;
}

void cpy(char *s1 , char *s2)
{
	for (int i = 0 ; i < len ; ++i) s2[i] = s1[i] ;
}

int main()
{
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%s" , s[i]) ;

	///

	int res = INF , t0 = 0 ;
	len = strlen(s[0]) ;
	for (int i = 0 ; i < len ; ++i)
	{
		int sum = t0 ; bool ok = 1 ;
		for (int j = 1 ; j < n ; ++j)
		{
			cpy(s[j] , ns) ;

			int t = 0 ; bool ans = 0 ;
			for (int k = 0 ; k < len ; ++k)
			{
				if (cmp(s[0] , ns)) {ans = 1 ; break ;}

				down(ns) ; ++t ;
			}

			if (ans) sum += t ; else {ok = 0 ; break ;}
		}

		if (ok) res = std::min(sum , res) ;
		down(s[0]) ; ++t0 ;
	}

	if (res == INF) printf("-1\n") ;
	else printf("%d\n" , res) ;

	return 0 ;
}