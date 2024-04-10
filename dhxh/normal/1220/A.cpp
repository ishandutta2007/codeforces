#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int a = 0, b = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == 'z')b++;
		if(ch == 'n')a++;
	}
	
	for(i=1;i<=a;i++)printf("1 ");
	for(i=1;i<=b;i++)printf("0 ");
	printf("\n");
	
	return 0;
}