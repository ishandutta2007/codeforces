#include<stdio.h>
#include<algorithm>
#define R register int
int ct[1000],a[1000];
inline int Abs(int x){
	return x<0?-x:x;
}
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if(ct[x%m]!=0){
			printf("0");
			return 0;
		}
		ct[x%m]=1;
		a[i]=x;
	}
	x=1;
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			x=(long long)x*Abs(a[i]-a[j])%m;
		}
	}
	printf("%d",x);
	return 0;
}