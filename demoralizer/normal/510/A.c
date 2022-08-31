#include <stdio.h>
#include <string.h>
int main(){
	int n,m,k;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1)
			{printf("#");continue;}
			k=(i/2)%2;
			if((j==1&&k==0)||(j==m&&k==1))
			{printf("#");continue;}
			printf(".");
		}
		printf("\n");
	}
}