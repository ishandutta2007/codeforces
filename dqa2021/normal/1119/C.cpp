#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int A[510][510],B[510][510];
int C[510],D[510];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) scanf("%d",&B[i][j]),A[i][j]^=B[i][j];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) C[i]+=A[i][j];
		if (C[i]&1) return puts("No"),0;
	}
	for (int j=1;j<=m;j++)
	{
		for (int i=1;i<=n;i++) D[j]+=A[i][j];
		if (D[j]&1) return puts("No"),0;
	}
	puts("Yes");
	return 0;
}