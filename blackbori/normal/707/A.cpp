#include <cstdio>

int main()
{
	int n,m,i,j,c=0;
	char a[11];

	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%s",a);
			if(a[0]!='B' && a[0]!='W' && a[0]!='G') c=1;
		}
	}
	
	printf("%s\n",c==1?"#Color":"#Black&White");

	return 0;
}