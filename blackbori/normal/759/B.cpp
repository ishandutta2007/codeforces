#include <cstdio>
#include <algorithm>

using namespace std;

int A[101010],D[101010];
int X[101010],Y[101010];
int n;

int main()
{
	int i;
	scanf("%d",&n);

	X[0] = Y[0] = 1;
	for(i=1;i<=n;i++){
		scanf("%d",A+i);
		X[i] = X[i-1]; Y[i] = Y[i-1];
		while(A[i] - A[X[i]] >= 90) X[i]++;
		while(A[i] - A[Y[i]] >= 1440) Y[i]++;
	}

	for(i=1;i<=n;i++){
		D[i] = D[i-1]+20;
		if(X[i] && D[X[i]-1] + 50 < D[i]) D[i] = D[X[i]-1]+50;
		if(Y[i] && D[Y[i]-1] + 120 < D[i]) D[i] = D[Y[i]-1]+120;
		printf("%d\n",D[i]-D[i-1]);
	}

	return 0;
}