#include <cstdio>
#include <cstdlib>
int main()
{
	int N, M, Ans = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0;i <= 1000;i++)
		for(int j = 0;j <= 1000;j++)
			if (i * i + j == N && i + j * j == M)
				Ans++;
	printf("%d\n", Ans);

	return  0;
}