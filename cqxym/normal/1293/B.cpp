#include<stdio.h>
int main(){
	int x;
	double s=0;
	scanf("%d",&x);
	for(register int i=1;i<=x;i++){
		s+=1.0/i;
	}
	printf("%.6lf",s);
	return 0;
}