#include <stdio.h>
#include <ctype.h>

char s[100004];

int main(void){
	int lo = 0, up = 0, len;
	int i, m;
	int k;

	scanf("%s",s);
	for( len = 0; s[len]; len++ ){
		if( isupper( s[len] ) ){
			up++;
			s[len] = 1;
		}
		else{
			s[len] = 2;
		}
	}

	m = up;
	if( m > len - up ) m = len - up;

	for( i = 0; i < len - 1; i++ ){
		if( s[i] == 1 )
			up--;
		else
			lo++;

		if( s[i] < s[i+1] ){
			k = lo + up;
			if( k < m ) m = k;
		}
	}
	printf("%d\n", m );
	return 0;
}