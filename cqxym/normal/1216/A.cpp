#include<stdio.h>
#define R register int
char q[200001];
int main(){
	int n,s=0;
	scanf("%d\n",&n);
	n>>=1;
	char a,b;
	for(R i=0;i<n;i++){
		a=getchar();
		b=getchar();
		if(a==b){
			s++;
		}
		q[i<<1]=a;
		q[i<<1|1]=b;
	}
	printf("%d\n",s);
	for(R i=0;i<n;i++){
		if(q[i<<1]==q[i<<1|1]){
			printf("ab");
		}else{
			printf("%c%c",q[i<<1],q[i<<1|1]);
		}
	}
	return 0;
}