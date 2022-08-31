#include <stdio.h>
#include <string.h>
int x(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,a,b,c,p=0,q,r,max=0;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	if(a>b){a=a+b;b=a-b;a=a-b;}
	if(a>c){a=a+c;c=a-c;a=a-c;}
	if(b>c){b=b+c;c=b-c;b=b-c;}
	while((p*a)<=n){
		q=0;
		while((p*a+q*b)<=n){
			r=(n-p*a-q*b)/c;
			if((p*a+q*b+r*c)==n)
			max=x(max,p+q+r);
			q++;
		}
		p++;
	}
	printf("%d",max);
}