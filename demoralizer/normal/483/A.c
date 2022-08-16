#include <stdio.h>
#include <string.h>
long long int cop(long long int a,long long int b){
	if(a==0)return (b==1);
	if(b==0)return (a==1);
	if(a>b)return cop(a%b,b);
	else return cop(a,b%a);
}
int main(){
	long long int l,r,i,j,k;
	scanf("%I64d %I64d",&l,&r);
	for(i=l;i<r-1;i++){
		for(j=i+1;j<r;j++)
		if(cop(i,j))
		for(k=j+1;k<=r;k++)
		if(cop(j,k)&&(cop(i,k)==0)){
		printf("%I64d %I64d %I64d",i,j,k);
		return 0;
		}
	}
	printf("-1");
}