#include <cstdio>

using namespace std;


int n,k,D[555][555],i,j,s,a;

int main()
{
	scanf("%d %d",&n,&k);
	a=n*n;
	
	for(i=1;i<=n;i++){
		for(j=n;j>=k;j--){
			D[i][j]=a;
			a--;
		}
	}
	for(i=1;i<=n;i++){
		for(j=k-1;j>=1;j--){
			D[i][j]=a;
			a--;
		}
	}
	
	for(i=1;i<=n;i++) s+=D[i][k];
	
	printf("%d\n",s);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",D[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}