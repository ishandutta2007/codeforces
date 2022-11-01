#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 2000000;

struct node
{
	int num;
	int next, pre;
	node()
	{
		next = pre = num = 0;
	}
}p[MAXN];
int n, top = 0, now;
char str[MAXN];

int main()
{

	gets(str + 1);
	n = strlen(str + 1);
	now = top = 1;
	p[top].num = 1;
	for(int i = 1; i <= n; i++)
	{
		p[now].num = i;
		if (str[i] == 'l')
		{
			++top;
			p[top].next = now;
			p[p[now].pre].next = top;
			p[top].pre = p[now].pre;
			p[now].pre = top;
			now = top;
		} else
		{
			++top;
			p[top].next = p[now].next;
			p[p[now].next].pre = top;
			p[top].pre = now;
			p[now].next = top;
			now = top;
		}
	}
	while(p[now].pre)
		now = p[now].pre;
	while(now)
	{
		if (p[now].num)
			printf("%d\n", p[now].num);
		now = p[now].next;
	}
	return 0;
}