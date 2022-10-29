#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int t[1000];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	if (num >= gen || num == 4)
	{
		printf("-1\n");
		return 0;
	}
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	a--;
	b--;
	c--;
	d--;
	t[a] = 1, t[b] = 1, t[c] = 1, t[d] = 1;
	vector<int>v;
	for (int i = 0; i < num; i++)if (t[i] == 0)v.push_back(i);
	printf("%d %d", a + 1, c + 1);
	for (int i = 0; i < num - 4; i++)
	{
		printf(" %d", v[i] + 1);
	}
	printf(" %d %d\n", d + 1, b + 1);
	printf("%d %d", c + 1, a + 1);
	for (int i = 0; i < num - 4; i++)
	{
		printf(" %d", v[i] + 1);
	}
	printf(" %d %d\n", b + 1, d + 1);
}