#include <cstdio>

double P[10101][1010];
int Ans[1010];
int k,q;

int main()
{
	int i,j,p=0;

	scanf("%d%d",&k,&q);

	P[0][0] = 1;
	for(i=1;i<=k*10;i++){
		for(j=1;j<=k;j++){
			P[i][j] = P[i-1][j-1] * (k-j+1)/k + P[i-1][j] * j/k;
		}
		while(P[i][k] >= p/2000.0 && p<=1000) Ans[p] = i, p++;
	}

	for(;q--;){
		scanf("%d",&i);
		printf("%d\n",Ans[i]);
	}

	return 0;
}