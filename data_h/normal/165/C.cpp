#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000000;
int N, K;
char str[MAXN];
long long Ans = 0;
struct node
{
	int x;
	long long num;
}block[MAXN];
int tot = 0;
void Init()
{
	scanf("%d\n",&K);
	gets(str + 1);
	N = strlen(str + 1);
}

void Work()
{
	for(int i = 1, j;i <= N;i++)
	{
		if (str[i] == '1')
		{
			block[++tot] = (node){1, 1};
		}
		else
		{
			for(j = i;j <= N && str[j] == str[i];j++);
			block[++tot] = (node){0, j - i};
			i = j - 1;
		}
	}
	if (K == 0)
	{
		for(int i = 1;i <= tot;i++)
			if (block[i].x == 0)
				Ans += (block[i].num * (block[i].num + 1)) / 2;
		printf("%I64d\n",Ans);
		return;
	}
	int now = 0;
	for(int i = 1, j = 0;i <= tot;i++)
	if (block[i].x == 1)
	{
		if (j < i)
		{
			j = i;
			now = 1;
		}
		while(now < K && j + 1 <= tot)
		{
			j++;
			if (block[j].x == 1)
				now++;
		}
		if (now == K)
		{
			long long L = 1,R = 1;
			if (i > 1 && block[i - 1].x == 0)
				L += block[i - 1].num;
			if (j < tot && block[j + 1].x == 0)
				R += block[j + 1].num;
			Ans += L * R;
		}
		now--;
	}
	printf("%I64d\n",Ans);
}

int main()
{
	Init();
	Work();
	return 0;
}