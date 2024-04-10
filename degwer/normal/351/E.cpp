#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int d[2000];
int rui[2001][2001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>zat;
	for (int i = 0; i < num; i++)scanf("%d", &d[i]), zat.push_back(abs(d[i]));
	sort(zat.begin(), zat.end());
	for (int i = 0; i < num; i++)d[i] = lower_bound(zat.begin(), zat.end(), abs(d[i])) - zat.begin();
	for (int i = 0; i < num; i++)rui[i + 1][d[i] + 1]++;
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)rui[i + 1][j + 1] += rui[i + 1][j] + rui[i][j + 1] - rui[i][j];
	int ans = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		vector<int>v1, v2;
		for (int j = 0; j < num; j++)
		{
			if (d[j] == i)
			{
				v1.push_back(rui[num][i] - rui[num][0] - rui[j + 1][i] + rui[j + 1][0]);
				v2.push_back(rui[j][i] - rui[j][0] - rui[0][i] + rui[0][0]);
			}
		}
		int sum = 0;
		for (int j = 0; j < v1.size(); j++)sum += v1[j];
		int mini = 1000000000;
		for (int j = 0; j <= v1.size(); j++)
		{
			mini = min(mini, sum);
			if (j == v1.size())break;
			sum -= v1[j];
			sum += v2[j];
		}
		ans += mini;
	}
	printf("%d\n", ans);
}