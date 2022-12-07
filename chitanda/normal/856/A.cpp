#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 110, VMAX = 1000100;

int T, N;
int number[NMAX], diff[NMAX * NMAX];
int b[NMAX];
bool val[VMAX];

int main()
{
	int i, j, k, t;
	bool flag;
	scanf("%d", &T);
	for(t = 0;t < T;t += 1)
	{
		memset(val, 0, sizeof(val));
		memset(diff, 0, sizeof(diff));
		flag = true;
		scanf("%d", &N);
		for(i = 1;i <= N;i += 1)
		{
			scanf("%d", &number[i]);
			if(val[number[i]])
				flag = false;
			val[number[i]] = true;
		}
		sort(number + 1, number + N + 1);
		if(!flag)
			printf("NO\n");
		else if(N == 1)
			printf("YES\n1\n");
		else
		{
			for(i = 1;i <= N;i += 1)
			{
				for(j = i + 1;j <= N;j += 1)
					diff[++diff[0]] = number[j] - number[i];
			}
			memset(val, 0, sizeof(val));
			sort(diff + 1, diff + diff[0] + 1);
			diff[0] = unique(diff + 1, diff + diff[0] + 1) - diff - 1;
			printf("YES\n");
			for(i = 1;i <= N;i += 1)
			{
				for(j = b[i - 1] + 1;val[j];j += 1);
				b[i] = j;
				printf("%d%c", b[i], " \n"[i == N?1:0]);
				for(k = 1;k <= diff[0];k += 1)
					val[diff[k] + b[i]] = true;
			}
		}
	}
	exit(0);
}