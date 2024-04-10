#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b, c, d;

int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(a > b) printf("First\n"); else printf("Second\n");
	return 0;
}