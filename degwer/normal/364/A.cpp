#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll dat[100000];
int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		int now = 0;
		for (int j = i; j < s.size(); j++)
		{
			now += s[j] - '0';
			dat[now]++;
		}
	}
	if (n == 0)
	{
		printf("%I64d\n", dat[0] * (s.size()*(s.size() + 1) / 2) *2 - dat[0] * dat[0]);
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i < 100000; i++)
	{
		if (n%i == 0 && n / i < 100000)
		{
			ans += dat[i] * dat[n / i];
		}
	}
	printf("%I64d\n", ans);
}