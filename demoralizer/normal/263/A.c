#include <stdio.h>
#include <string.h>
int bb(int n){
	return (n>0)?n:-n;
}
int main(){
	int t,x,y;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++){
		  scanf("%d",&t);
		  if(t==1){x=i;y=j;break;}
		}
	printf("%d",bb(x-3)+bb(y-3));
}