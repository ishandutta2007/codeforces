#include <stdio.h>
#include <math.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char a;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&a);
		if(a=='\n'){j--;continue;}
		if(a=='-'){printf("-");continue;}
			printf("%c",((i+j)%2)?'W':'B');
		}
		printf("\n");
	}
}