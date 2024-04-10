#include <stdio.h>
#include <vector>
#include <algorithm>
#define M 10000000

using namespace std;

vector<int> ans;
int N, K;
int a[2005];
int b[2005];
int x[20000005];
bool chk[2005];

int main()
{
	scanf("%d %d", &K, &N);

	for(int i = 0; i < K; i++)
	{
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &b[i]);

		x[b[i] + M] = i + 1;
	}

	for(int i = 1; i <= K; i++)
	{
		for(int j = 0; j <= N; j++)	chk[j] = false;

		chk[x[b[0] + M]] = true;

		int now = b[0];
		for(int j = i + 1; j <= K; j++)
		{
			now += a[j - 1];
			chk[x[now + M]] = true;
		}

		now = b[0];
		for(int j = i - 1; j > 0; j--)
		{
			now -= a[j];
			chk[x[now + M]] = true;
		}
		now -= a[0];
		bool can = true;
		for(int i = 1; i <= N; i++)	if(!chk[i])	can = false;
		if(can)	ans.push_back(now);
	}

	sort(ans.begin(), ans.end());
	int ret = 0;

	for(int i = 0; i < ans.size(); i++)
	{
		ret++;
		if(i == 0)	continue;
		if(ans[i] == ans[i - 1])	ret--;
	}
	printf("%d", ret);
	return 0;
}