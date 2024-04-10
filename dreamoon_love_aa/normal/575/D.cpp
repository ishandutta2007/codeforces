#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std ;

int main(void)
{
	printf("2000\n") ;
	
	for(int i=1;i<=1000;i++)
		printf("%d 1 %d 2\n",i,i,i,i) ;
		
	for(int i=1000;i>=1;i--)
		printf("%d 1 %d 2\n",i,i,i,i) ;
	
	return 0 ;
}