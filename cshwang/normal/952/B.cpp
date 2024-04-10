#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

std::string s ;

int main() {
	for (int i = 9 ; i >= 0 ; --i) {
		printf("%d\n" , i) ;
		getline(std::cin , s) ;

		int ty = 0 ;
		if (s == "great!") ty = 1 ;
		else if (s == "not bad") ty = 1 ;
		else if (s == "cool") ty = 1 ;
		else if (s == "don't think so") ty = 1 ;
		else if (s == "don't touch me!") ty = 1 ;
		else if (s == "don't even") ty = 2 ;
		else if (s == "terrible") ty = 2 ;
		else if (s == "worse") ty = 2 ;
		else if (s == "are you serious?") ty = 2 ;
		else if (s == "go die in a hole") ty = 2 ;
		else if (s == "no way") ty = 2 ;

		if (ty) {
			if (ty == 1) printf("normal\n") ;
			else printf("grumpy\n") ;

			return 0 ;
		}
	}

	return 0 ;
}