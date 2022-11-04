#include<cstdio>
#include<algorithm>

using namespace std;

int a[(int)1e5], b[(int)1e5];

struct chislo
{
	int ind, value;
	bool operator < (const chislo &a)const
	{
		return value < a.value;
	}
};

chislo mas[3 * (int)1e5];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int minn = (int)1e5 + 1;
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < minn)
			minn = a[i];
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] > maxx)
			maxx = b[i];
	}
	if (minn < maxx)
	{
		for (int i = 0; i < n; i++)
		{
			mas[i].value = a[i];
			mas[i].ind = 1;
		}
		for (int i = 0; i < m; i++)
		{
			mas[n + i].value = b[i];
			mas[n + i].ind = 2;
		}
		sort(mas, mas + n + m);
		long long ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i] < mas[0].value)
				ans += mas[0].value - a[i];
		for (int i = 0; i < m; i++)
			if (b[i] > mas[0].value)
				ans += b[i] - mas[0].value;
		long long minn = ans;
		int col1 = 0;
		int col2;
		if (mas[0].ind == 2)
			col2 = m - 1;
		else
			col2 = m;
		for (int i = 1; i < n + m; i++)
		{
			if (mas[i - 1].ind == 1)
				col1++;
			ans += ((long long)mas[i].value - (long long)mas[i - 1].value) * ((long long)col1 - (long long)col2);
			if (mas[i].ind == 2)
				col2--;
			if (ans < minn)
				minn = ans;
		}
		printf("%I64d", minn);
	}
	else
		printf("0");
	return 0;
}