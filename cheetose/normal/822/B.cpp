#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char s[1001], w[1001];
	scanf("%s%s", s, w);
	int start = -1, cnt = 1005;
	for (int i = 0; i <= m - n; i++)
	{
		int t = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[j] != w[i + j])t++;
		}
		if (t < cnt)
			start = i, cnt = t;
	}
	printf("%d\n",cnt);
	for (int i = 0; i < n; i++)
	{
		if (s[i] != w[start + i])
			printf("%d ", i+1);
	}
}