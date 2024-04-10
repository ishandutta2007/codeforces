#include<cstdio>
int mas[1000][1000];
int main()
{
	//freopen("stdin.in", "r", stdin);
	//freopen("stdout.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&mas[i][j]);
	int answer = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			answer = (answer + mas[i][j] * mas[j][i]) % 2;
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int c;
		scanf("%d", &c);
		if(c == 3)
			printf("%d", answer);
		else
		{
			answer = 1 - answer;
			scanf("%d",&c);
		}
	}
	return 0;
}