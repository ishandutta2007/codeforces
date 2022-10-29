#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll rui[5000001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	string s;
	cin >> s;
	ll sum = 0;
	for (int i = 0; i < num; i++)
	{
		if (s[i] == 'A')rui[i + 1] = rui[i] - v[i];
		else rui[i + 1] = rui[i] + v[i];
		if (s[i] == 'B')sum += v[i];
	}
	ll maxi = 0;
	for (int i = 0; i < num; i++)
	{
		maxi = max(maxi, -rui[i + 1]);
		maxi = max(maxi, -(rui[num] - rui[i]));
	}
	printf("%I64d\n", sum + maxi);
}