#include<stdio.h>
int Min(int a,int b){
	return a<b?a:b;
}
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	b=Min(b,c);
	if(e<f){
		c=Min(b,d);
		printf("%d",c*f+Min(d-c,a)*e);
	}else{
		c=Min(a,d);
		printf("%d",c*e+Min(d-c,b)*f);
	}
	return 0;
}