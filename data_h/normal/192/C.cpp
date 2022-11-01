#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 600000;

int N, Ans;
struct node
{
	char a, b;
	int len;
}s[MAXN];
char str[MAXN];
int sum[MAXN], f[26][26], g[26][26];

void Init()
{
	scanf("%d\n", &N);
	for(int i = 1;i <= N;i++)
	{
		gets(str + 1);
		int len = strlen(str + 1);
		s[i].a = str[1]; s[i].b = str[len];
		s[i].len = len;
	}
}


void Work()
{
	for(int i = 1;i <= N;i++)
		sum[i] = sum[i - 1] + s[i].len;
	for(int i = 0;i < 26;i++)
		for(int j = 0;j < 26;j++)
			f[i][j] = -100000000;
	for(int i = N;i >= 1;i--)
	{
		int d1 = s[i].a - 'a', d2 = s[i].b - 'a';
		for(int j = 0;j < 26;j++)
			g[d1][j] = s[i].len + f[d2][j];
		for(int j = 0;j < 26;j++)
			f[d1][j] = max(f[d1][j], g[d1][j]);
		f[d1][d2] = max(f[d1][d2], s[i].len);
	}
	for(int i = 0;i < 26;i++)
		Ans = max(Ans, f[i][i]);
	printf("%d\n", Ans);
}

int main()
{
	Init();
	Work();
	return 0;
}