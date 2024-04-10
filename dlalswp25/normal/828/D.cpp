#include <stdio.h>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	if((N - 1) % K == 0)	printf("%d\n", 2 * (N - 1) / K);
	else if((N - 1) % K == 1)	printf("%d\n", 2 * ((N - 1) / K) + 1);
	else	printf("%d\n", 2 * ((N - 1) / K) + 2);

	for(int i = 0; i < K; i++)
	{
		printf("%d %d\n", 1, i + 2);
		q.push(i + 2);
	}

	int nextnode = K + 2;

	while(nextnode <= N)
	{
		int now = q.front();
		q.pop();
		printf("%d %d\n", now, nextnode);
		q.push(nextnode);
		nextnode++;
	}

	return 0;
}