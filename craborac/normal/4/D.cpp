#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

struct convert
{
	int w, h, id;
	bool operator <(const convert &a)const
	{
		if(w == a.w)
			return h < a.h;
		return w < a.w;
	}
};

convert mas[6000];
int dp[6000];
int prevv[6000];
int ans[6000];

int main()
{
	int n, w, h;
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &mas[i].w, &mas[i].h);
		mas[i].id = i + 1;
	}
	sort(mas, mas + n);
	for (int i = 0; i < n; i++)
	{
		int maxx = -1;
		int max_ind = -1;
		if ((mas[i].w > w) && (mas[i].h > h))
			maxx = 0;
		for (int j = 0; j < i; j++)
		{
			if ((mas[i].w > w) && (mas[i].h > h) && (mas[i].w > mas[j].w) && (mas[i].h > mas[j].h) && (dp[j] > maxx))
			{
				maxx = dp[j];
				max_ind = j;
			}
		}
		prevv[i] = max_ind;
		dp[i] = maxx + 1;
	}
	int max_ind = -1;
	int maxx = 0;
	for (int i = 0; i < n; i++)
		if (dp[i] > maxx)
		{
			maxx = dp[i];
			max_ind = i;
		}
	int col = 0;
	int i = max_ind;
	while (i != -1)
	{
		ans[col++] = i;
		i = prevv[i];
	}
	printf("%d\n", col);
	for (int i = col - 1; i >= 0; i--)
		printf("%d ", mas[ans[i]].id);

	return 0;
}