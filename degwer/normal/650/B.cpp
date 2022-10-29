#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll rui[500001];
int main()
{
	int num;
	ll ta, tb, gen;
	scanf("%d%I64d%I64d%I64d", &num, &ta, &tb, &gen);
	string str;
	cin >> str;
	for (int i = 0; i < num; i++)
	{
		if (str[i] == 'w')rui[i + 1] = rui[i] + 1 + tb;
		else rui[i + 1] = rui[i] + 1;
	}
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		ll t = rui[i + 1];
		ll m = gen - t - ta*i;
		if (m >= 0)
		{
			int beg = i + 1, end = num;
			for (;;)
			{
				int med = (beg + end) / 2;
				if (rui[num] - rui[med] + ta*(num - med + i) <= m)
				{
					end = med;
				}
				else beg = med + 1;
				if (beg == end)break;
			}
			maxi = max(maxi, i + 1 + num - beg);
		}
	}
	for (int i = 1; i <= num; i++)
	{
		ll t = rui[1] + rui[num] - rui[i];
		ll m = gen - t - ta*(num - i);
		if (m >= 0)
		{
			int beg = 0, end = i - 1;
			for (;;)
			{
				int med = (beg + end + 1) / 2;
				if (rui[med + 1] - rui[1] + ta*(med + num - i) <= m)
				{
					beg = med;
				}
				else end = med - 1;
				if (beg == end)break;
			}
			maxi = max(maxi, num - i + 1 + beg);
		}
	}
	printf("%d\n", maxi);
}