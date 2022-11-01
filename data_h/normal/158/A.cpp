#include <cstdio>
#include <cstdlib>
int N, A[300], Ans, K;

void Init()
{
	scanf("%d %d",&N,&K);
	for(int i = 1;i <= N;i++)
		scanf("%d",&A[i]);
	for(int i = 1;i <= N;i++)
		if (A[i] && A[i] >= A[K])
			Ans++;
}

void Work()
{
	printf("%d\n",Ans);
}

int main()
{
	Init();
	Work();
	return 0;
}