#include <stdio.h>
#include <stdlib.h>

double hp , mp , sp ;
int h , m , s , t1 , t2 ;

int main() {
	scanf("%d %d %d %d %d" , &h , &m , &s , &t1 , &t2) ;
	
	///

	if (h == 12) h -= 12 ;
	if (t1 == 12) t1 -= 12 ;
	if (t2 == 12) t2 -= 12 ;
	sp = s ; mp = m + (s / 60.0) ; hp = h + (mp / 60.0) ;
	hp *= 5 ; t1 *= 5 ; t2 *= 5 ;

	///

	bool s1 = 1 , s2 = 1 ;
	for (int i = t1 ; i != t2 && s1 ; i = (i + 1) % 60) {
		int ni = (i + 1) % 60 ;
		if (ni == 0) ni = 60 ;

		if (i <= hp && hp <= ni) s1 = 0 ;
		else if (i <= mp && mp <= ni) s1 = 0 ;
		else if (i <= sp && sp <= ni) s1 = 0 ;
	}
	for (int i = t1 ; i != t2 && s2 ; i = (i + 59) % 60) {
		int ni = (i + 59) % 60 ;
		if (i == 0) i = 60 ;

		if (ni <= hp && hp <= i) s2 = 0 ;
		else if (ni <= mp && mp <= i) s2 = 0 ;
		else if (ni <= sp && sp <= i) s2 = 0 ;
	}

	if (s1 || s2) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}