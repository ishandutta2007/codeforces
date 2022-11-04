#include<cstdio>
#include<algorithm>

using namespace std;

struct tree
{
	int day, frut;
	bool operator <(tree const a)const
	{
		return day < a.day;
	}
};
tree mas[4000];
int main()
{
	int n, v;
	scanf("%d%d", &n, &v);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &mas[i].day, &mas[i].frut);
	}
	sort(mas, mas + n);
	mas[n].day = mas[n - 1].day + 10;
	mas[n].frut = 0;
	long long ans = 0;
	long long col1 = 0;
	long long col2 = 0;
	int dayy = 1;
	int q = 0;
	while(q <= n)
	{
		long long qq = v;
		qq = max((long long)0, qq - col2);
		col2 -= v - qq;
		ans += v - qq;
		while(dayy == mas[q].day)
		{
			col1 += mas[q].frut;
			q++;
		}
		if(qq > 0)
		{
			long long qqq = qq;
			qqq = max((long long)0, qqq - col1);
			col1 -= qq - qqq;
			ans += qq - qqq;
		}
		dayy++;	
		col2 = col1;
		col1 = 0;
	}
	printf("%I64d", ans);
	return 0;
}