#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int rui[3][100001];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)for (int j = 0; j < 3; j++)rui[j][i + 1] = rui[j][i] + (s[i] == 'x' + j);
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		int maxi = 0, mini = 1000000000;
		for (int j = 0; j < 3; j++)maxi = max(maxi, rui[j][zb + 1] - rui[j][za]), mini = min(mini, rui[j][zb + 1] - rui[j][za]);
		if (maxi - mini <= 1 || zb - za + 1 <= 2)printf("YES\n");
		else printf("NO\n");
	}
}