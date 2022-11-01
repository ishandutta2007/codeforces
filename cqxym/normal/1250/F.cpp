#include<stdio.h>
#define R register int
#define E return 0;
int ct[100001];
int main(){
	int n,x,a;
	scanf("%d%d",&n,&x);
	for(R i=0;i<n;i++){
		scanf("%d",&a);
		ct[a]++;
		if(ct[a]>1){
			printf("0");
			E
		}
	}
	for(R i=0;i<100001;i++){
		if(i!=(i&x)&&ct[i]+ct[i&x]>1){
			printf("1");
			E
		}
	}
	for(R i=0;i<100001;i++){
		ct[i&x]+=ct[i];
		ct[i]=0;
	}
	for(R i=0;i<=x;i++){
		if(ct[i]>1){
			printf("2");
			E
		}
	}
	printf("-1");
	E
}