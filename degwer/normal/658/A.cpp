#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, c;
	scanf("%d%d", &num, &c);
	vector<int>p, t;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		p.push_back(z);
	}
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		t.push_back(z);
	}
	int sa = 0, sb = 0;
	int now = 0;
	for (int i = 0; i < num; i++)
	{
		now += t[i];
		sa += max(0, p[i] - now*c);
	}
	now = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		now += t[i];
		sb += max(0, p[i] - now*c);
	}
	if (sa > sb)printf("Limak\n");
	else if (sa == sb)printf("Tie\n");
	else printf("Radewoosh\n");
}