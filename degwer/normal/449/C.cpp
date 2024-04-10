#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	for (;;)
	{
		if (a > b)swap(a, b);
		b %= a;
		if (b == 0)return a;
	}
}
int match[100001];
vector<int>pr[100001];
int isp[100001];
bool flag[100001];
int get(int now, int num)
{
	int r1 = rand() % pr[now].size();
	int r2 = rand() % (num / pr[now][r1]) + 1;
	return pr[now][r1] * r2;
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)match[i] = i;
	for (int i = 2; i <= 100000; i++)
	{
		if (pr[i].empty())
		{
			for (int j = i; j <= 100000; j += i)pr[j].push_back(i);
			isp[i] = 1;
		}
	}
	int cnt = 0;
	fill(flag, flag + 100001, false);
	for (int i = 2; i <= num; i++)
	{
		if (isp[i] == 1 && i * 2 > num)continue;
		cnt++;
		if (match[i] != i)continue;
		if (i % 2 == 0)continue;
		vector<int>v;
		for (;;)
		{
			bool f = true;
			v.push_back(i);
			flag[i] = true;
			int now = get(i, num);
			if (flag[now])
			{
				goto l01;
			}
			v.push_back(now);
			flag[now] = true;
			for (;;)
			{
				if (match[now] == now)break;
				if (flag[match[now]])
				{
					goto l01;
				}
				v.push_back(match[now]);
				flag[match[now]] = true;
				now = get(match[now], num);
				if (flag[now])
				{
					goto l01;
				}
				v.push_back(now);
				flag[now] = true;
			}
			break;
		l01:;
			for (int i = 0; i < v.size(); i++)flag[v[i]] = false;
			v.clear();
		}
		for (int i = 0; i < v.size() / 2; i++)match[v[i * 2]] = v[i * 2 + 1], match[v[i * 2 + 1]] = v[i * 2];
	}
	vector<int>v;
	for (int i = 2; i <= num; i += 2)if (match[i] == i)v.push_back(i);
	for (int i = 0; i < v.size() / 2; i++)match[v[i * 2]] = v[i * 2 + 1], match[v[i * 2 + 1]] = v[i * 2];
	printf("%d\n", cnt / 2);
	int r = 0;
	for (int i = 1; i <= num; i++)if (match[i] > i)printf("%d %d\n", i, match[i]), r++;
	if (r != cnt / 2)abort();
}