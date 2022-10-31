#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1000005
#define ll long long
int T, n, a[MAXN], s[MAXN], top, top1, tmp;
ll k;
char tmp2[MAXN];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		top=tmp=top1=0;
		scanf("%d%lld", &n, &k);
		scanf("%s", tmp2+1);
		for(int i=1; i<=n; ++i) a[i]=tmp2[i]-'0', s[i]=s[i-1]+a[i];
		for(int i=1; i<=n; ++i)
		{
			if(a[i]==0&&k>=s[i]) k-=s[i], ++top, top1=i;
			else if(a[i]==0) { tmp=i; break; }
		}
		for(int i=1; i<=top; ++i) putchar('0');
		for(int i=top+1; i<=top1; ++i) putchar(i==tmp-k?'0':'1');
		for(int i=top1+1; i<=n; ++i) putchar(i==tmp-k?'0':i==tmp?'1':a[i]?'1':'0');
		puts("");
	}
	return 0;
}