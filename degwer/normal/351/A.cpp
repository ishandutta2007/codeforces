#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	int sum = 0, cnt = 0;
	for (int i = 0; i < num + num; i++)
	{
		string s;
		cin >> s;
		int x = 100 * (s[s.size() - 3] - '0') + 10 * (s[s.size() - 2] - '0') + (s[s.size() - 1] - '0');
		if (x == 0)cnt++;
		sum += x;
	}
	int mini = 1000000000;
	for (int i = 0; i <= cnt; i++)
	{
		mini = min(mini, abs(-sum + (num - i) * 1000));
	}
	printf("%d.%03d\n", mini / 1000, mini % 1000);
}