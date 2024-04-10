#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 110000;

struct node
{
	int l, r;
	int id;
}p[MAXN];
int n, a[MAXN], b[MAXN], num = 0, c[MAXN], del[MAXN];

int main()
{
	scanf("%d", &n);
	p[0].id = -1; p[0].r = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[i].r = i + 1;
		p[i].l = i - 1;
		p[i].id = a[i];
	}
	p[n + 1].id = a[n + 1] = 100000000; p[n + 1].l = n;
	for(int i = 1; i <= n; i++) {
		if (a[i] > a[i + 1]) {
			b[++num] = i + 1;
		}
	}
	int ans = 0;
	while(num) {
		ans++;
		int num2 = num; num = 0;
		for(int j = 1; j <= num2; j++) {
			int x = b[j];
			p[p[x].r].l = p[x].l;
			p[p[x].l].r = p[x].r;
			if (p[x].l != 0 && p[x].r != n + 1 && p[p[x].l].id > p[p[x].r].id)
				c[++num] = p[x].r;
			del[x] = 1;
		}
		num2 = num; num = 0;
		for(int i = 1; i <= num2; i++)
			if (!del[c[i]])
				b[++num] = c[i];
		int x = 0;
		//while(x != n + 1) {
		//	x = p[x].r;
		//	printf("%d ", p[x].id);
		//}
		//printf("\n");
	}
	printf("%d\n", ans);
	return 0;
}