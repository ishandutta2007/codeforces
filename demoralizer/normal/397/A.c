#include <stdio.h>
#include <string.h>
int main(){
	int n,a,b,c=0;
	scanf("%d\n%d %d",&n,&a,&b);
	int z[100];
	for(int i=0;i<100;i++)
		if(i>=a&&i<b)z[i]=1;
		else z[i]=0;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&a,&b);
		for(int j=a;j<b;j++)
			z[j]=0;
	}
	for(int i=0;i<100;i++)
		if(z[i])c++;
	printf("%d",c);
}