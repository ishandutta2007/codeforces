#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
	scanf("%d%d%d",&a,&b,&n);
	if (a>b+n){
		printf("+");
		return 0;
	} else 
	if (b>n+a){
		printf("-");
		return 0;
	} else 
	if (n==0&&a==b){
		printf("0");
		return 0;
	} else {
		printf("?");
		return 0;
	}
	return 0;
}