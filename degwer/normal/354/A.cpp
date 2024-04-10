#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, l, r, cl, cr;
	scanf("%d%d%d%d%d", &num, &l, &r, &cl, &cr);
	vector<int>v;
	int now = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
		now += z;
	}
	now *= r;
	int mini = 2100000000;
	for (int i = 0; i <= v.size(); i++)
	{
		if (i < v.size() - i)
		{
			mini = min(mini, now + int(v.size() - i - i - 1)*cr);
		}
		else if (i + i == v.size())mini = min(mini, now);
		else
		{
			mini = min(mini, now + int(i + i - v.size() - 1)*cl);
		}
		if (i == v.size())break;
		now -= r*v[i];
		now += l*v[i];
	}
	printf("%d\n", mini);
}