#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll num, p;
	scanf("%I64d%I64d", &num, &p);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		v.push_back(s.size() / 4);
	}
	ll now = 0;
	ll sum = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		if (v[i] == 2)now = now * 2 + 1;
		else now = now * 2;
		sum += now*p / 2;
	}
	printf("%I64d\n", sum);
}