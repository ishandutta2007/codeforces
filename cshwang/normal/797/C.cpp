#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 100000 + 10 ;

int len ;
std::stack<char> t ;
char s[MAX_N] , u[MAX_N] , ms[MAX_N] ;

int main()
{
	scanf("%s" , s) ; len = strlen(s) ;
	ms[len - 1] = s[len - 1] ;
	for (int i = len - 2 ; i >= 0 ; --i) ms[i] = std::min(ms[i + 1] , s[i]) ;

	///
	
	for (int i = 0 ; i < len ; ++i)
		if (t.empty()) {t.push(s[i]) ; continue ;}
		else
		{
			while (!t.empty() && t.top() <= ms[i]) printf("%c" , t.top()) , t.pop() ;
			t.push(s[i]) ;
		}
	while (!t.empty()) printf("%c" , t.top()) , t.pop() ;

	return 0 ;
}