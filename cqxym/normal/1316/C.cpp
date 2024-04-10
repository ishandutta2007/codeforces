#include<stdio.h>
#define R register int
int a[1000000];
int main(){
	int n,m,p,x,y;
	scanf("%d%d%d",&n,&m,&p);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=n;i++){
		if(a[i]%p!=0){
			x=i;
			break;
		}
	}
	for(R i=0;i!=m;i++){
		scanf("%d",&y);
		if(y%p!=0){
			printf("%d",x+i);
			return 0;
		}
	}
}