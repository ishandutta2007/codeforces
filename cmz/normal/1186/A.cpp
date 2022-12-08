#include<cstdio>
#include<iostream>
using namespace std;
int n,a,b;
int kkk;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	a=min(a,b);
	if (n>a) printf("No"); else printf("Yes"); 
	return 0;
}