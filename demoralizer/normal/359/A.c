#include <stdio.h>
#include <string.h>
int main(){
	int n,m,t;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&t);
			if(t&&((i==1)||(i==n)||(j==1)||(j==m)))
				{printf("2");return 0;}
		}
	printf("4");
}