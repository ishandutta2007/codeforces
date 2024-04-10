#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
char str[300];
int len, N;
struct node
{
	char str[300];
	int len;
}d[60 * 40];
int low = 1, top, l;

void Init()
{
	scanf("%d\n",&N);
}

void Insert(char *s,int l,int r)
{
	top++;
	d[top].len = r - l + 1;
	for(int i = l;i <= r;i++)
		d[top].str[i - l + 1] = s[i];
}

void Work()
{
	for(int i = 1;i <= N;i++)
	{
		gets(str);
		l = strlen(str);
		if (l == 3 && str[0] == 'p' && str[1] == 'w' && str[2] == 'd')
		{
			printf("/");
			for(int i = low;i <= top;i++)
			{
				for(int j = 1;j <= d[i].len;j++)
					printf("%c",d[i].str[j]);
				printf("/");
			}
			printf("\n");
		}
		else
		{
			for(int st = 3, stop;st < l;st++)
			{
				while(st < l && str[st] == '/')
					st++, low = top + 1;
				stop = st;
				while(stop < l && str[stop] != '/')
					stop++;
				if (stop - st == 2 && str[st] == '.' && str[st + 1] == '.')
					top--;
				else
					Insert(str, st, stop - 1);
				st = stop;
			}
		}
	}
}

int main()
{
	Init();
	Work();
	return 0;
}