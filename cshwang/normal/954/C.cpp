#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 2e5 + 10 ;

int n , a[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

	///

	bool ok = 1 ;
	int last = -1 ;
	for (int i = 1 ; i < n && ok ; ++i) {
		int d = abs(a[i] - a[i - 1]) ;
		if (d == 1) continue ;

		if (!d) ok = 0 ;

		if (last == -1) last = d ;
		else if (last != d) ok = 0 ;
	}

	for (int i = 1 ; i < n && ok ; ++i) {
		int d = a[i] - a[i - 1] ;
		if (last == -1) continue ;

		if (d == 1 && !(a[i - 1] % last)) ok = 0 ;
		if (d == -1 && !(a[i] % last)) ok = 0 ;
	}

	///

	if (ok) printf("YES\n") ;
	else printf("NO\n") ;

	if (last == -1) last = 1 ;
	if (ok) printf("1000000000 %d\n" , last) ;

	return 0 ;
}