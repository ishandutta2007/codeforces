#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int main()
{
	int i, a;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &a);
		if(a == 1) x ++;
		else y ++;
	}
	
	if(x == 0){
		for(i=0; i<y; i++) printf("2 ");
		printf("\n");
	}
	else if(y == 0){
		for(i=0; i<x; i++) printf("1 ");
		printf("\n");
	}
	else{
		printf("2 1 "); x--, y--;
		for(i=0; i<y; i++) printf("2 ");
		for(i=0; i<x; i++) printf("1 ");
		printf("\n");
	}
	
	return 0;
}