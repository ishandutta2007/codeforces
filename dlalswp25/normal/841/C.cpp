#include <stdio.h>
#include <algorithm>

using namespace std;

int M;
struct arr
{
	int x;
	int idx;
};

arr A[200005];
arr B[200005];
int ans[200005];

bool cmpA(arr s, arr t)
{
	return s.x > t.x;
}

bool cmpB(arr s, arr t)
{
	return t.x > s.x;
}

int main()
{
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &A[i].x);
		A[i].idx = i;
	}
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &B[i].x);
		B[i].idx = i;
	}

	sort(A, A + M, cmpA);
	sort(B, B + M, cmpB);

	for(int i = 0; i < M; i++)
	{
		ans[B[i].idx] = A[i].x;
	}

	for(int i = 0; i < M; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}