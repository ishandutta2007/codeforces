#include <bits/stdc++.h>

const int MAX_N = 40 + 5 ;

int T , n ;
char s[MAX_N] , t[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %s" , &n , s) ;
		for (int i = 0 ; i < n ; ++i) t[i] = s[i] ;

		///

		std::sort(t + 0 , t + n) ;

		int res = 0 ;
		for (int i = 0 ; i < n ; ++i)
			if (s[i] != t[i]) ++res ;
		printf("%d\n" , res) ;
	}

	return 0 ;
}