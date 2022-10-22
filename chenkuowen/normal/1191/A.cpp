#include<bits/stdc++.h>
using namespace std;
char check(int x){ 
	if(x%4==0) return 'D';
	if(x%4==3) return 'B';
	if(x%4==2) return 'C';	
	return 'A';
}
int main(){
	int x; scanf("%d",&x);
	if(check(x)<=check(x+1)&&check(x)<=check(x+2))
		printf("%d %c\n",0,check(x));
	else if(check(x+1)<=check(x+2))
		printf("%d %c\n",1,check(x+1));
	else 
		printf("%d %c\n",2,check(x+2));
	return 0;
}