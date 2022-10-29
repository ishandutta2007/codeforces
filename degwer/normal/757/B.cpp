#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int>dat[100001];
int ans[100001];
int main()
{
	for (int i = 2; i <= 100000; i++)
	{
		if (!dat[i].empty())continue;
		for (int j = i; j <= 100000; j += i)dat[j].push_back(i);
	}
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		for (int j = 0; j < dat[z].size(); j++)ans[dat[z][j]]++;
	}
	int maxi = 1;
	for (int i = 0; i <= 100000; i++)maxi = max(maxi, ans[i]);
	printf("%d\n", maxi);
}