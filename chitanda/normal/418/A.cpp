#include <cstdio>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if (2*k>=n) printf("-1\n"); else{
		printf("%d\n",n*k);
		for(int i=1;i<=n;i++)
			for(int j=0;j<k;j++)
				printf("%d %d\n",i,(i+j)%n+1);
	}
	return 0;
}