#include <stdio.h>
int p[100004], a[100004], b[100004], n, i;
int main(void){
	scanf("%d", &n );
	for( i = 0; i++ < n; )
		scanf("%d",a+i);
	for( i = 0; i++ < n; )
		scanf("%d",b+i);
	for( i = 0; i++ < n; )
		p[a[i]] = b[i];
	for( i = 0; i++ < n; ){
		printf("%d",p[i] );
		putchar( i == n ? '\n' : ' ' );
	}
	return 0;
}