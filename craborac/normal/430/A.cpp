#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

struct point
{
	int a, ind;
	bool operator <(point aa)const
	{
		if(a < aa.a)
			return true;
		else
			return false;
	}
};
point mas[100];
int l[100], r[100], ans[100];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i].a);
		mas[i].ind = i;
	}
	sort(mas, mas + n);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &l[i], &r[i]);
	}
	int q = 0;
	for(int i = 0; i < n; i++)
	{
		ans[mas[i].ind] = q;
		q = 1 - q;
	}
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}