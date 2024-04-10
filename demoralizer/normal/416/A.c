#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,u=1000005000,l=-1000005000;
	scanf("%d",&n);
for(int i=0;i<n;i++){
	int x;
	char a,b,c;
	scanf("\n%c%c%d %c",&a,&b,&x,&c);
	if(a=='<'^c=='Y')
		l=max(l,x+(b=='='^c=='Y'));
	else
		u=min(u,x-(b=='='^c=='Y'));
}
	if(l>u)
		printf("Impossible");
	else
		printf("%d",l);
}