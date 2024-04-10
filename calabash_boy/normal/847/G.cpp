#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAXN 1005
#define MAXL 7

int n;
char str[MAXL];
int num[MAXL];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);

		for (int k = 0; k < MAXL; k++)
			if (str[k] == '1')
				num[k]++;
	}

	int m = 0;
	for (int i = 0; i < MAXL; i++)
		m = max(m, num[i]);
	printf("%d\n", m);

	return 0;
}