#include<cstdio>
long long n,m,t;
int main(){
	scanf("%I64d%I64d",&n,&m);
	if(n>m)t=n,n=m,m=t;
	if(n==1){
	  switch(m%6){
		case 0:printf("%I64d",m);break;
		case 1:printf("%I64d",m-1);break;
		case 2:printf("%I64d",m-2);break;
		case 3:printf("%I64d",m-3);break;
		case 4:printf("%I64d",m-2);break;
		case 5:printf("%I64d",m-1);break;
	  }
	  return 0;
	}
	if(n==2){
	  switch(m){
		case 1:printf("%I64d",0ll);break;
		case 2:printf("%I64d",0ll);break;
		case 3:printf("%I64d",4ll);break;
		case 7:printf("%I64d",12ll);break;
		default:printf("%I64d",m*2);
	  }
	  return 0;
	}
	printf("%I64d",n*m/2*2);
	return 0;
}