#include<stdio.h>
#define R register int
int a[100],b[100];
int main(){
	int n,ct1=0,ct2=0;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=n;i++){
		scanf("%d",b+i);
		if(a[i]==1&&b[i]==0){
			ct1++;
		}else if(a[i]==0&&b[i]==1){
			ct2++;
		}
	}
	if(ct1==0){
		printf("-1");
	}else{
		printf("%d",ct2/ct1+1);
	}
	return 0;
}