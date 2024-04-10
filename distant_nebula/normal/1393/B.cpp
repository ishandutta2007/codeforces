#include <cstdio>
#define N 100005
int n, q, cnt[N], ct2, ct4, ct6, ct8;
char s[3];
inline void upt(int x, int v) { x>=2?ct2+=v:0; x>=4?ct4+=v:0; x>=6?ct6+=v:0; x>=8?ct8+=v:0; }
int main()
{
	scanf("%d", &n);
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), upt(cnt[x], -1), upt(++cnt[x], 1);
	scanf("%d", &q);
	for(int i=1, x; i<=q; ++i)
	{
		scanf("%s%d", s, &x);
		if(s[0]=='+') upt(cnt[x], -1), upt(++cnt[x], 1);
		else upt(cnt[x], -1), upt(--cnt[x], 1);
		puts((ct4&&(ct8||ct4>=2||(ct2+ct6-1>=2)))?"YES":"NO");
	}
	return 0;
}