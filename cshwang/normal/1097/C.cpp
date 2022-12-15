#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define cnt(x) cnt[x + offset]
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 , MAX_L = 1e6 + 10 , offset = 5e5 ;

char s[MAX_L] ;
int n , len , mL , cnt[MAX_L] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s) ;
		len = strlen(s) ; mL = std::max(mL , abs(len)) ;

		bool sta = 1 ; int sum = 0 , lf = 0 ;
		for (int i = 0 ; i < len ; ++i) {
			if (s[i] == '(') ++sum , ++lf ;
			else {
				--sum ;
				if (lf) --lf ;
			}

			if (sum < 0) sta = 0 ;
		}

		if (sum >= 0 && sta) ++cnt(sum) ;
		else if (sum < 0 && !lf) ++cnt(sum) ;
	}

	///

	int ans = 0 ;
	for (int i = -mL ; i < 0 ; ++i) ans += std::min(cnt(i) , cnt(-i)) ;
	ans += cnt(0) >> 1 ;

	printf("%d\n" , ans) ;

	return 0 ;
}