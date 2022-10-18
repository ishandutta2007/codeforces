#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define MIN(A, B) ((A)<(B)?(A):(B))

int n, x[5005], p[5005];
int flag = 0;

int gen()
{
	n = 350;
	int i, j, xx;
/*
	flag++;

	if(flag%50==0)
	{
		for(i = 0;i<n;i++)
		{
			while(1)
			{
				xx = rand()%1000001;

				for(j=0;j<i;j++)
					if(x[j] == xx)
						break;

				if(j==i)
				{
					x[i] = xx;
					break;
				}
			}

		}

		sort(x, x+n);
	}

	for(i = 0; i<n; i++)
		p[i] = 1 + rand()%1000000;
*/

	int gg = rand()%10;
	int ff = 1000 + rand()%8000;

//	printf("%d %d\n", gg, ff);
	x[0] = 0;
	p[0] = 1000000;
	for(i=1;i<n-1;i++)
	{
		x[i] = x[i-1] + gg*(n-i);
		p[i] = ff;
	}

	x[n-1] = 1000000;
	p[n-1] = 1000000;

	return 1;
}

void print()
{
	int i;
	printf("%d\n", n);
	for(i = 0; i < n; i++)
		printf("%d %d\n", x[i], p[i]);

}

double radius[6000];
int s[6000];
int maxSz;

void Relax(int i, int j)
{
	int t = s[j];
	radius[i] = MIN(radius[i], (1.*x[i] - x[t])*(x[i]-x[t])/(4*radius[t]));
}

double solve1()
{
	double sum;

	int Rsz, Ssz;
	int i, j;

	Rsz = 0;
	Ssz = 0;
	sum = 0;

	for(i = 0; i < n; i++)
	{
		radius[Rsz++] = p[i];
		for(j = 0; j < MIN(Ssz, 300); j++)
			Relax(i, Ssz - j - 1);

		while(Ssz && radius[ s[Ssz-1] ] <= radius[i])
			Ssz--;
		s[Ssz++] = i;
		sum += radius[i];
		if(maxSz < Ssz)
			maxSz = Ssz;
	}

	return sum;
}

double solve2()
{
	double sum;

	int Rsz, Ssz;
	int i, j;

	Rsz = 0;
	Ssz = 0;
	sum = 0;

	for(i = 0; i < n; i++)
	{
		radius[Rsz++] = p[i];
		for(j = 0; j < Ssz; j++)
			Relax(i, Ssz - j - 1);

		s[Ssz++] = i;
		sum += radius[i];
	}

	return sum;
}

int main()
{
//	freopen("ans.txt", "w", stdout);

	double ans1, ans2;

	while(gen())
	{
//		maxSz = 0;
		ans1 = solve1();
		ans2 = solve2();

//		printf("%d\n", maxSz);
//		if(maxSz > 300)
//			break;

//		printf("%lf %lf\n", ans1, ans2);
		if(fabs(ans1 - ans2) > 1e-4)
		{
			print();
			break;
		}
	}

	return 0;
}