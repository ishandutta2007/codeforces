#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

struct bomb
{
	int x, y;
	bool operator <(bomb const &a)const
	{
		return (abs(x) + abs(y) < abs(a.x) + abs(a.y));
	}
};

bomb mas[(int)1e5];

int main()
{
	int n;
	scanf("%d", &n);
	long long col = 0;
	for (int i = 0; i < n; i++)
	{
		col += 2;	
		int xx, yy;
		scanf("%d %d", &xx, &yy);
		if(xx != 0)
			col += 2;
		if(yy != 0)
			col += 2;
		mas[i].x = xx;
		mas[i].y = yy;
	}	
	sort(mas, mas + n);
	printf("%I64d\n", col);
	for (int i = 0; i < n; i++)
	{
		int xx = mas[i].x;
		int yy = mas[i].y;
		if (xx > 0)
			printf("1 %d R\n", xx);
		if (xx < 0)
			printf("1 %d L\n", -xx);
		if (yy > 0)
			printf("1 %d U\n", yy);
		if (yy < 0)
			printf("1 %d D\n", -yy);	
		printf("2\n");
		if (xx > 0)
			printf("1 %d L\n", xx);
		if (xx < 0)
			printf("1 %d R\n", -xx);
		if (yy > 0)
			printf("1 %d D\n", yy);
		if (yy < 0)
			printf("1 %d U\n", -yy);
		printf("3\n");
	}
	return 0;
}