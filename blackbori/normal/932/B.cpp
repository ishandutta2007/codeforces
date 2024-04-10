#include <bits/stdc++.h>

using namespace std;

int D[1010101];
int K[1010101][11];

int digit(int p)
{
	int ret = 1;
	for(;p;p/=10){
		if(p%10) ret *= p%10;
	}
	return ret;
}

int main()
{
	int i,j,a,b,c,q;
	
	for(i=1;i<10;i++){
		D[i] = i;
		for(j=1;j<10;j++) K[i][j] = K[i-1][j];
		K[i][D[i]] ++;
	}
	for(i=10;i<=1e6;i++){
		D[i] = D[digit(i)];
		for(j=1;j<10;j++) K[i][j] = K[i-1][j];
		K[i][D[i]] ++;
	}
	
	scanf("%d",&q);
	
	for(;q--;){
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",K[b][c] - K[a-1][c]);
	}
	
	return 0;
}