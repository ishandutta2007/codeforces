#include <cstdio>

using namespace std;

typedef long long LL;

int A[2222][2];

int main()
{
	int n,k,x,a,c,s,i;
	bool j;

	scanf("%d%d%d",&n,&k,&x);

	for(i=0;i<n;i++){
		scanf("%d",&a);
		A[a][0]++;
	}

	for(j=0;k--;j=!j){
		for(i=s=0;i<=2047;i++){
			c = (s+A[i][j]+1)/2-(s+1)/2;
			A[i][!j] += A[i][j]-c;
			A[i^x][!j] += c;
			s += A[i][j];
			A[i][j] = 0;
		}
	}

	for(i=2047;i>=0;i--){
		if(A[i][j]){
			printf("%d ",i);
			break;
		}
	}

	for(i=0;i<=2047;i++){
		if(A[i][j]){
			printf("%d\n",i);
			break;
		}
	}

	return 0;
}