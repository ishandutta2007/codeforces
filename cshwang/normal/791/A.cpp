#include <stdio.h>
#include <stdlib.h>
using namespace std ;

int a , b , res ;

int main()
{
	scanf("%d %d" , &a , &b) ;

	for (res = 0 ; a <= b ; ++res) {a *= 3 ; b *= 2 ;}

	printf("%d\n" , res) ;
}