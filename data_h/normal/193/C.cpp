#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

/*
* 1 : abbb
* 2 : babb
* 3 : bbab
* 4 : bbba
* 5 : aabb
* 6 : abab
* 7 : abba
*/ 

const int MAXN = 30;

int a[5][5], Mat[MAXN][MAXN], len;
char str[4][16 * 100000];

void Init()
{
	for(int i = 1;i <= 3;i++)
		for(int j = i;j <= 3;j++)
			scanf("%d", &a[i][j]);
	Mat[1][1] = Mat[1][2] = Mat[1][6] = Mat[1][7] = 1; Mat[1][8] = a[1][1];
	Mat[2][1] = Mat[2][3] = Mat[2][5] = Mat[2][7] = 1; Mat[2][8] = a[1][2];
	Mat[3][1] = Mat[3][4] = Mat[3][5] = Mat[3][6] = 1; Mat[3][8] = a[1][3];
	Mat[4][2] = Mat[4][3] = Mat[4][5] = Mat[4][6] = 1; Mat[4][8] = a[2][2];
	Mat[5][2] = Mat[5][4] = Mat[5][5] = Mat[5][7] = 1; Mat[5][8] = a[2][3];
	Mat[6][3] = Mat[6][4] = Mat[6][6] = Mat[6][7] = 1; Mat[6][8] = a[3][3];
//	for(int i = 1;i <= 6;i++, printf("\n"))
//		for(int j = 1;j <= 7;j++)
//			printf("%d ", Mat[i][j]);
}

const int N = 6, M = 8;
int tmp[MAXN], u[MAXN], Ans = 2000000000, t[MAXN], ch[MAXN];

inline int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void fail()
{
	printf("-1\n");
	exit(0);
}

void Solve()
{
	for(int i = 1;i <= 6;i++)
	{
		int p = Mat[i][M] - Mat[i][7] * u[7];
		if (p % Mat[i][i] != 0)
			return;
		u[i] = p / Mat[i][i];
		if (u[i] < 0)
			return;
	}
	int res = 0;
	for(int i = 1;i <= 7;i++)
		res += u[i];
	if (res < Ans)
	{
		Ans = res;
		for(int i = 1;i <= 7;i++)
			t[i] = u[i];
	}
}

void Work()
{
	int base = 0;
	for(int i = 1;i <= N;i++)
	{
//		for(int j = 1;j <= N;j++, printf("\n"))
//		for(int k = 1;k <= M;k++)
//			printf("%d ", Mat[j][k]);
//		printf("\n");
		if (i == 3)
			i = 3;
		int p;
		for(p = i;p <= N && Mat[p][i] == 0;p++);
		if (p > N)
		{
			base++;
			continue;
		}
		for(int j  = 1;j <= M;j++)
			swap(Mat[i][j], Mat[p][j]);
		for(int j = 1;j <= N;j++)
			if (j != i && Mat[j][i] != 0)
			{
				int Target = Mat[i][i] * Mat[j][i] / gcd(Mat[i][i], Mat[j][i]);
				int r = Target / Mat[i][i];
				for(int k = 1;k <= M;k++)
					tmp[k] = Mat[i][k] * r;
				r = Target / Mat[j][i];
				for(int k = 1;k <= M;k++)
					Mat[j][k] = Mat[j][k] * r;
				for(int k = 1;k <= M;k++)
					Mat[j][k] -= tmp[k];
			}
	}
//	for(int i = 1;i <= N;i++, printf("\n"))
//		for(int j = 1;j <= M;j++)
//			printf("%d ", Mat[i][j]);
	for(u[7] = 0;u[7] <= a[1][1];u[7]++)
	{
		Solve();
	}
	if (Ans == 2000000000)
		fail();
	printf("%d\n", Ans);
	for(int i = 1;i <= t[1];i++)
		str[0][++len] = 'a', str[1][len] = 'b', str[2][len] = 'b', str[3][len] = 'b';
	for(int i = 1;i <= t[2];i++)
		str[0][++len] = 'b', str[1][len] = 'a', str[2][len] = 'b', str[3][len] = 'b';
	for(int i = 1;i <= t[3];i++)
		str[0][++len] = 'b', str[1][len] = 'b', str[2][len] = 'a', str[3][len] = 'b';
	for(int i = 1;i <= t[4];i++)
		str[0][++len] = 'b', str[1][len] = 'b', str[2][len] = 'b', str[3][len] = 'a';
	for(int i = 1;i <= t[5];i++)
		str[0][++len] = 'a', str[1][len] = 'a', str[2][len] = 'b', str[3][len] = 'b';
	for(int i = 1;i <= t[6];i++)
		str[0][++len] = 'a', str[1][len] = 'b', str[2][len] = 'a', str[3][len] = 'b';
	for(int i = 1;i <= t[7];i++)
		str[0][++len] = 'a', str[1][len] = 'b', str[2][len] = 'b', str[3][len] = 'a';
	for(int i = 0;i <= 3;i++, printf("\n"))
		for(int j = 1;j <= Ans;j++)
			printf("%c", str[i][j]);
}

int main()
{
	Init();
	Work();
	return 0;
}