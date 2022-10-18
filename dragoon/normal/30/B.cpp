#include<stdio.h>

int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int mm,dd,yy;
int bm, bd, by;

int valid(int d, int m, int y)
{
	if(y==0) return 0;
	if(m>12) return 0;

	int l;

	if(y%4==0) l=1;
	else l=0;

	if(m==2)
	{
		if(l+days[m]>=d) return 1;
		return 0;
	}

	if(days[m]>=d) return 1;
	return 0;
}

int C(int d, int m, int y)
{
	if(!valid(d,m,y)) return 0;

	if(y>=yy) return 0;

	if(d==dd && m==mm)
		return (yy>=y+18);

	if(mm>m || (mm==m && dd>d))
		return yy>=y+18;

	return yy>y+18;
}

int main()
{
	int check;

	scanf("%d.%d.%d",&dd,&mm,&yy);
	scanf("%d.%d.%d",&bd,&bm,&by);

	check = 0;
	check |= C(bd, bm, by);
	check |= C(bd, by, bm);
	check |= C(bm, bd, by);
	check |= C(bm, by, bd);
	check |= C(by, bm, bd);
	check |= C(by, bd, bm);

	if(check)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}