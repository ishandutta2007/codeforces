#include <stdio.h>
int p[3];
int main()
{
	int a[3][3],z=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			p[i]+=a[i][j];
			z+=a[i][j];
		}
	z/=2;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==j)a[i][j]=z-p[i];
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}